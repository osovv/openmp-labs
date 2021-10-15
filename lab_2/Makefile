CC=g++
LIBS=-fopenmp -Isrc/lib

all: main

main: src/main.cpp
	${CC} ${CFLAGS} ${LIBS} src/lib/fort.c src/main.cpp -o bin/main

clean:
	rm bin/main
