cmake_minimum_required (VERSION 3.12)

project (deep_forte_on_kos_with_fboot)

# Initialize CMake library for KasperskyOS SDK.
include (platform)
initialize_platform ()

# Add functions for installing artefacts.
include (platform/install)

# Tests
include (platform/tests)
add_project_tests_main_target ()


# Platform definition
include (platform/options)

include (platform/nk)

nk_build_edl_files (forte_edl_files NK_MODULE "forte" EDL "resources/edl/Forte.edl")


if ("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "arm")
    # This command will find the BSP package components
    # (BSP_HW_ENTITY, BSP_QEMU_ENTITY and BSP_CLIENT_LIB)
    find_package (bsp REQUIRED)
    include_directories (${bsp_INCLUDE})
endif ()

# This command will find GPIO client lib
find_package (gpio REQUIRED COMPONENTS CLIENT_LIB ENTITY)
include_directories (${gpio_INCLUDE})

find_package (rump REQUIRED COMPONENTS DHCPCD_ENTITY)
include_directories (${rump_INCLUDE})

# Add a package with the VFS program implementations
find_package (precompiled_vfs REQUIRED)
include_directories (${precompiled_vfs_INCLUDE})

# Add package importing components for working with
# virtual file system.
find_package (vfs REQUIRED)
include_directories (${vfs_INCLUDE})

find_package (dnet REQUIRED COMPONENTS IMPLEMENTATION_LIB)

# Add package importing components for working with
# VFAT
find_package (VFAT REQUIRED)
include_directories (${VFAT_INCLUDE})

# Attach the directory with the generated config header files
include_directories (${CMAKE_CURRENT_BINARY_DIR})

# Attach the directories with programs.
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/resources/include)


option (ROOTFS_SDCARD "Use SD card to mount root filesystem" OFF)
message (STATUS "Use SD card to mount root filesystem - ${ROOTFS_SDCARD}")

add_subdirectory (forte)
add_subdirectory (einit)
