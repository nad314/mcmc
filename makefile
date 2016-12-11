CC = g++
BIN = bin
BUILD = build

all:
	$(CC) mcmc/program/main.cpp -o $(BIN)/main.o
	$(CC) $(BIN)/main.o -o $(BUILD)/mcmc.run
	./$(BUILD)/mcmc.run
	