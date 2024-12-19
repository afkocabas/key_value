CC = gcc
CFLAGS = -Wall -Wextra -pthread
SRC = src/main.c
OUT = build/key_value_store

all: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)
run: all
	./$(OUT)
clean:
	rm -rf build/*
