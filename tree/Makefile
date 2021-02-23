CC=gcc
CFLAGS=-Wall
BINS=treeexample

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) $^ -o $@.o

clean:
	$(RM) $(BINS)
