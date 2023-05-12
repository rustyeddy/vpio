.PHONY: all clean

all: build

build: 
	mkdir build	
	cd build && cmake ..
	make

clean:
	rm -rf build
