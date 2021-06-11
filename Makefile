SRC_FILES=$(wildcard src/* include/*)

.PHONY: clean

SFML_DIR ?=
CMAKE_BUILD_TYPE ?= Debug

CMAKE_ARGS := -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_TYPE)

ifneq ($(SFML_DIR),)
	CMAKE_ARGS += -DSFML_DIR=$(SFML_DIR)
endif

all: proj

build:
	mkdir -p $@
	touch $@

proj: build build/Sandbox compile_commands.json

build/Sandbox: $(SRC_FILES) CMakeLists.txt
	cd build && cmake $(CMAKE_ARGS) .. && make
	touch $@

compile_commands.json: build/Sandbox
	cp build/$@ $@

clean:
	rm -rf build
