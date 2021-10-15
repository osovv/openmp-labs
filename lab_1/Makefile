CC=g++
LIBS=-fopenmp

all: main

main: src/main.cpp
	${CC} ${CFLAGS} ${LIBS} src/main.cpp -o bin/main

clean:
	rm bin/main
