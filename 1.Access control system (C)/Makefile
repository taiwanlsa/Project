# Makefile #
all: doorAccess
 
doorAccess: doorAccess.o cardOpt.o
	gcc -g -std=c11 -Wall -o $@ $^

%.o: %.c
	gcc -c -g -std=c11 -Wall -o $@ $^

clean:
	rm doorAccess *.o
