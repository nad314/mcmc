CC = g++
BIN = bin
BUILD = build
INCLUDE = -I"mcmc/"
FLAGS = -O2 $(INCLUDE)
OBJ = $(BIN)/main.o


all:
	$(CC) -c mcmc/program/main.cpp -o $(BIN)/main.o $(FLAGS)
	$(CC) $(OBJ) -o $(BUILD)/mcmc.run
	./$(BUILD)/mcmc.run
	