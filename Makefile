CFLAGS=-Wall -g

dynamic_lib:
	cc -o sort.c sort.o $(CFLAGS)
	cc -o sort.o sort.so

tests:
	rm -f test
	make test
	./test
