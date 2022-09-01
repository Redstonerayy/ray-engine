.PHONY: build
build:
	CC=/usr/bin/clang CXX=/usr/bin/clang++ cmake -B ./build .
	make -C ./build

clean:
	rm -rf ./build
	rm -rf ./run

run: build
	mkdir -p ./run
	cp ./build/libengine.so ./run/libengine.so
	# ./run/engine