LIB=libSDL2gfx.so
CC=gcc
CFLAGS=-Wall -Wpedantic -O3 -fPIC
LDFLAGS=-lSDL2 -shared

src=$(shell find ./ -type f -name '*.c')
obj=$(src:.c=.o)

build_all: $(obj)
	$(CC) $^ -o $(LIB) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) $(LIB)
