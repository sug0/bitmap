all:
	@echo === Making lib ===
	@echo
	gcc -Wall -O2 -std=c11 -c -fPIC -o bitmap.o bitmap.c
	gcc -shared -Wl,-soname,libbitmap.so -o libbitmap.so bitmap.o
	mkdir -p lib
	mv libbitmap.so lib
	@echo
	@echo === Making tests ===
	@echo
	mkdir -p bin
	gcc -Wall -O2 -std=c11 -o bin/test test.c bitmap.o
	gcc -Wall -O2 -std=c11 -o bin/test2 test2.c bitmap.o
	gcc -Wall -O2 -std=c11 -o bin/test3 test3.c bitmap.o

install:
	cp bitmap.h /usr/local/include
	cp lib/libbitmap.so /usr/local/lib

clean:
	rm -rf bin
	rm -rf lib
	rm -f bitmap.o
