project (einit)

# Tools for using NK parser.
include (platform/image)

# Set compile flags.
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

if ("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "arm|aarch64")
    # Add package importing components for working with SD card.
    find_package (sdcard REQUIRED)
    include_directories (${sdcard_INCLUDE})

    # We need SDCARD driver to be connected with our implementation of VFS
    set_target_properties (Forte PROPERTIES ${blkdev_ENTITY}_REPLACEMENT ${sdcard_ENTITY})

    # For the Arm architecture only one SD card supported.
    set (QEMU_FLAGS "-nographic -monitor none -sd hdd.img")
else ()
    # Add package importing components for working with ata device.
    find_package (ata REQUIRED)
    include_directories (${ata_INCLUDE})

    # We need ATA driver to be connected with our implementation of VFS
    set_target_properties (Forte PROPERTIES ${blkdev_ENTITY}_REPLACEMENT ${ata_ENTITY})

    set (QEMU_FLAGS "-nographic -monitor none \
                     -device ahci,id=ahci \
                     -drive id=disk,file=hdd.img,if=none \
                     -device ide-drive,drive=disk,bus=ahci.0")
endif ()

set (SECURITY_PSL_FILE "src/security.psl.in")
set (CONNECTIONS_CFG "src/init.yaml.in")

# KasperskyOS image for target hardware platform.
build_kos_hw_image (kos-image
                    EINIT_ENTITY EinitHw
                    CONNECTIONS_CFG ${CONNECTIONS_CFG}
                    SECURITY_PSL ${SECURITY_PSL_FILE}
                    IMAGE_FILES Forte)

# KasperskyOS image for QEMU with simulation targets (sim, gdbsim, gdb).
build_kos_qemu_image (kos-qemu-image
                      EINIT_ENTITY EinitQemu
                      CONNECTIONS_CFG ${CONNECTIONS_CFG}
                      SECURITY_PSL ${SECURITY_PSL_FILE}
                      QEMU_FLAGS ${QEMU_FLAGS}
                      IMAGE_FILES Forte)

#set_target_properties (EinitQemu PROPERTIES LINK_FLAGS "-Ttext 0x00200000")
