#src-m := src/mbfs.c
obj-m := mbfs.o
mbfs-objs := src/mbfs.o
EXTRA_CFLAGS += -DDEBUG

BUILD_DIR ?= $(PWD)/build
BUILD_DIR_MAKEFILE ?= $(PWD)/build/Makefile

all:$(BUILD_DIR_MAKEFILE)
	make -C /lib/modules/$(shell uname -r)/build M=$(BUILD_DIR) src=$(PWD) modules
$(BUILD_DIR):
	mkdir -p "$@"
$(BUILD_DIR_MAKEFILE):$(BUILD_DIR)
	touch "$@"
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(BUILD_DIR) src=$(PWD) clean
