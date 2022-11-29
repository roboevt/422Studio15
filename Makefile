# TODO: Change this to the location of your kernel source code
KERNEL_SOURCE=/home/roboevt/dev/422/linux/linux

EXTRA_CFLAGS += -DMODULE=1 -D__KERNEL__=1

kernel_memory-objs := $(kernel_memory-y)
obj-m := studio15.o

PHONY: all

all:
	$(MAKE) -C $(KERNEL_SOURCE) ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_SOURCE) ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- M=$(PWD) clean 