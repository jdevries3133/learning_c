CC = clang
CFLAGS = -Wall -g
SRC = $(wildcard src/*.c)
BIN = bin
PROG = hello.vm

all: dirs main

run: all
	$(BIN)/main $(PROG)

dirs:
	mkdir -p ./$(BIN)

main:
	$(CC) $(SRC) -o $(BIN)/main $< $(CFLAGS)

clean:
	$(RM) -rf $(BIN)
