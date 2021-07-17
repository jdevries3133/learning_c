CC = clang
CFLAGS = -Wall -g
SRC = $(wildcard *.c) ../binary_search/rar.c
LFLAGS = -I../binary_search
BIN = bin

all: dirs main

run: all
	$(BIN)/main

dirs:
	mkdir -p ./$(BIN)

main:
	$(CC) $(SRC) -o $(BIN)/main $< $(CFLAGS) $(LFLAGS)

clean:
	$(RM) -rf $(BIN)
