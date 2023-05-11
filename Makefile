.PHONY: all clean

all: build

build: 
	mkdir build	
	cd build && cmake ..

clean:
	rm -rf build
