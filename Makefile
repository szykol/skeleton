SRC_FILES=$(wildcard Skeleton/src/* Sandbox/src/*)

.PHONY: clean

all: proj

build:
	mkdir -p $@
	touch $@

proj: build build/Sandbox compile_commands.json

build/Sandbox: $(SRC_FILES) CMakeLists.txt
	cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make
	touch $@

compile_commands.json: build/Sandbox
	cp build/$@ $@

clean:
	rm -rf build
