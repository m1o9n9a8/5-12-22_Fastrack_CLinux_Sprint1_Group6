
CC = gcc
INC = include
SRC = src
OBJ = obj
BIN = bin

CFLAGS = -c -g -Wall
OFLAGS = -lm -o
IFLAGS = -I $(INC)

VFLAGS = v --tool=memcheck --leak-check=yes --show-reachable=yes

EXECS = $(BIN)/myvote


$(BIN)/myvote:$(OBJ)/main.o $(OBJ)/functions.o 
	$(CC) $(OFLAGS)myvote $(OBJ)/main.o $(OBJ)/functions.o 
	mv myvote $(BIN)

$(OBJ)/main.o: $(SRC)/main.c $(INC)/header.h
	$(CC) $(CFLAGS) $(SRC)/main.c $(IFLAGS)
	mv main.o $(OBJ)/

$(OBJ)/functions.o: $(SRC)/functions.c $(INC)/header.h
	$(CC) $(CFLAGS) $(SRC)/functions.c $(IFLAGS)
	mv functions.o $(OBJ)

clean:
	rm -f $(OBJ)/*myvote.o
	rm -f $(BIN)/myvote
	echo "Cleaning Done!"
