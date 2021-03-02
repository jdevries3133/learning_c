CC = clang  # change compiler to gcc and bear works fine.
CFLAGS = -Wall
SRC = $(wildcard src/*.c)
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
