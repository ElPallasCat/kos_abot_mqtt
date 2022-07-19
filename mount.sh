#!/bin/bash

sudo mount /dev/sdb1 /home/slava/mnt/fat32/
sudo cp build/einit/kos-image /home/slava/mnt/fat32/kos-image
sync
sudo umount /home/slava/mnt/fat32
