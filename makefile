CC = g++ -std=c++11
BIN = bin
BUILD = build
INCLUDE = -I"mcmc/"
LIBS = -lpython2.7
FLAGS = -O2 $(INCLUDE)
OBJ = $(BIN)/main.o


all:
	$(CC) -c mcmc/program/main.cpp -o $(BIN)/main.o $(FLAGS)
	$(CC) $(OBJ) -o $(BUILD)/mcmc.run $(LIBS)
	./$(BUILD)/mcmc.run
	
