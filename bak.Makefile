# Assemble bootloader: i586-elf-as boot.s -o boot.o
# Compile Kernel: i586-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
# Linking: i586-elf-gcc -T linker.ld -o ckern.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

# Create ISO
# cp $OUTBIN.bin isodir/boot/$OUTBIN.bin
# grub-mkrescue -o $OUTBIN.iso isodir

CC = /home/catix/opt/cross/bin/i586-elf-gcc 
AS = /home/catix/opt/cross/bin/i586-elf-as

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
CFLAGS = -g -ffreestanding $(WARNINGS)

LDFLAGS = -ffreestanding -O2 -nostdlib

MAIN = ckern

# define the C source files
SRCS = kernel.c rtc.c

OBJS = $(SRCS:.c=.o)

all: $(MAIN)

$(MAIN): $(OBJS) boot.o
	$(CC)-T linker.ld -o $(MAIN).bin $(LDFLAGS) boot.o $(OBJS) -lgcc
	echo Kernel linked to bootloader

	#objcopy --only-keep-debug ckern.bin ckern.sym
	objcopy -O binary $(MAIN).bin $(MAIN).sym
	echo symbol file generated

.c.o:
	$(CC) $(CFLAGS) -c $<  -o $@
	echo Kernel compiled

boot.o: boot.s
	$(AS) boot.s -o boot.o
	echo Bootloader assembled...

clean:
	$(RM) *.o *~ $(MAIN)
	echo ckern is now clean
	
mkiso:
	# rm *.iso
	cp $(MAIN).bin isodir/boot
	sudo grub-mkrescue -o $(MAIN).iso isodir/
	sudo chown catix:catix $(MAIN).iso

run:
	qemu-system-i386 -s -S $(MAIN).iso 

	
