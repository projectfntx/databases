PLATFORM=$(shell uname)
BUILD_PATH=cmake.bld/$(PLATFORM)
BUILD_PATH=build

default: all

init:
	cmake -B $(BUILD_PATH) -G Ninja

project:
	ninja -C $(BUILD_PATH) -j12

all:
	make init
	make project	

clean:
	ninja -C $(BUILD_PATH) -t clean

.PHONY: default all init clean
