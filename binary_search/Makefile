CC = clang
CFLAGS = -Wall -g
SRC = $(wildcard *.c)
BIN = bin

all: dirs main

run: all
	$(BIN)/main

dirs:
	mkdir -p ./$(BIN)

main:
	$(CC) $(SRC) -o $(BIN)/main $< $(CFLAGS)

clean:
	$(RM) -rf $(BIN)
