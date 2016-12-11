CC = g++
BIN = bin/

all:
	$(CC) mcmc/program/main.cpp -o $(BIN)/main.o