.PHONY: tests
CFLAGS=-Wall -g
LIBFLAGS=-shared

dynamic_lib:
	rm -f sort.o
	rm -f sort.so
	cc $(CFLAGS) $(LIBFLAGS) -o libsort.so -fPIC sort.h

tests:
	rm -f tests/test
	make tests/test
	tests/test
