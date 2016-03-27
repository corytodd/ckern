# Assemble bootloader: i586-elf-as boot.s -o boot.o
# Compile Kernel: i586-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
# Linking: i586-elf-gcc -T linker.ld -o ckern.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

# Create ISO
# cp $OUTBIN.bin isodir/boot/$OUTBIN.bin
# grub-mkrescue -o $OUTBIN.iso isodir

# Uber pedant
WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
            -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
            -Wuninitialized -Wconversion -Wstrict-prototypes

# Compiler flags
# -Wall turns on most, but not all, compiler warnings
# -std=gnu99 ??
# -ffreestanding because this is a kernel
# -lgcc ??
CFLAGS = -ffreestanding $(WARNINGS)

LDFLAGS = -ffreestanding -O2 -nostdlib

all: ckern.bin

ckern.bin: kernel.o boot.o
	/home/catix/opt/cross/bin/i586-elf-gcc -T linker.ld -o ckern.bin $(LDFLAGS) boot.o kernel.o -lgcc
	echo Kernel linked to bootloader

kernel.o: kernel.c
	/home/catix/opt/cross/bin/i586-elf-gcc -c kernel.c -o kernel.o $(CFLAGS)
	echo Kernel compiled

boot.o: boot.s
	/home/catix/opt/cross/bin/i586-elf-as boot.s -o boot.o
	echo Bootloader assembled...

clean:
	rm -rf *.o *.bin
	echo ckern is now clean
	
