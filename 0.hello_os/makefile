MAKEFLAGS = -sR
MKDIR = mkdir
RMDIR = rmdir
CP = cp
CD = cd
DD = dd
RM = rm

ASM		= nasm
CC		= gcc
LD		= ld
OBJCOPY	= objcopy

ASMBFLAGS	= -f elf -w-orphan-labels
CFLAGS		= -c -Os -std=c99 -m32 -Wall -Wshadow -W -Wconversion -Wno-sign-conversion  -fno-stack-protector -fomit-frame-pointer -fno-builtin -fno-common  -ffreestanding  -Wno-unused-parameter -Wunused-variable
LDFLAGS		= -s -static -T hello.lds -n -Map HelloOS.map
OJCYFLAGS	= -S -O binary

HELLOOS_OBJS :=
HELLOOS_OBJS += boot.o main.o
HELLOOS_ELF = HelloOS.elf
HELLOOS_BIN = HelloOS.bin

.PHONY : build clean all link bin

all: clean build link bin clear

clean:
	$(RM) -f *.o *.bin *.elf

build: $(HELLOOS_OBJS)

link: $(HELLOOS_ELF)
$(HELLOOS_ELF): $(HELLOOS_OBJS)
	$(LD) $(LDFLAGS) -o $@ $(HELLOOS_OBJS)

bin: $(HELLOOS_BIN)
$(HELLOOS_BIN): $(HELLOOS_ELF)
	$(OBJCOPY) $(OJCYFLAGS) $< $@

#清除编译中间产物
clear:
	$(RM) *.o *.elf *.map

%.o : %.asm
	$(ASM) $(ASMBFLAGS) -o $@ $<

%.o : %.c
	$(CC) $(CFLAGS) -o $@ $<

