#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/concur.kernel isodir/boot/concur.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "concur" {
	multiboot /boot/concur.kernel
}
EOF
grub-mkrescue -o concur.iso isodir
