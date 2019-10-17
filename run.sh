#!/bin/bash

mkdir -p mbclient
umount mbclient
rmmod mbfs
insmod build/mbfs.ko
mount -o loop -t mbfs image mbclient/
dmesg
