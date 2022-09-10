.PHONY: build
build:
	clear
	CC=/usr/bin/clang CXX=/usr/bin/clang++ cmake -B ./build -G Ninja .
	ninja -C ./build -j 14

clean:
	rm -rf ./build
	rm -rf ./run

run: build
	mkdir -p ./run
	cp ./build/libengine.so ./run/libengine.so
	cp ./build/lightray ./run/lightray
	./run/lightray
