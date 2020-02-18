# Definition des constantes
CC = gcc
CFLAGS = -Wall
EXEC = Minesweeper
LDFLAGS = -lMLV -lm
OBJ = $(BIN)main.o $(BIN)grid.o $(BIN)mines.o $(BIN)solver.o $(BIN)IGraph.o
OPT = -O2
INCLUDE = include/
SRC = src/
BIN = bin/


# Definition des commandes a effectuer
$(BIN)$(EXEC) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(BIN)main.o : $(SRC)main.c $(INCLUDE)grid.h $(INCLUDE)mines.h $(INCLUDE)IGraph.h

$(BIN)grid.o : $(SRC)grid.c $(INCLUDE)grid.h $(INCLUDE)mines.h

$(BIN)mines.o : $(SRC)mines.c $(INCLUDE)mines.h

$(BIN)IGraph.o : $(SRC)IGraph.c $(INCLUDE)IGraph.h $(INCLUDE)solver.h $(INCLUDE)grid.h $(INCLUDE)mines.h

$(BIN)solver.o : $(SRC)solver.c $(INCLUDE)solver.h $(INCLUDE)grid.h

$(BIN)%.o: $(SRC)%.c
	$(CC) -c $< $(CFLAGS) $(LDFLAGS) $(OPT) -o $@


# Définition des commandes de nettoyage
clean :
	rm -f $(BIN)*.o

mrproper : clean
	rm -f $(BIN)$(EXEC)
