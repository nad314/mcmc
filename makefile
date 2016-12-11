CC = g++
BIN = bin
BUILD = build
OBJ = $(BIN)/main.o


all:
	$(CC) -c mcmc/program/main.cpp -o $(BIN)/main.o
	$(CC) $(OBJ) -o $(BUILD)/mcmc.run
	./$(BUILD)/mcmc.run
	