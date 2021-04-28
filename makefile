# Definition des constantes
CC = gcc
CFLAGS = -Wall
EXEC = Minesweeper
LDFLAGS = -lMLV -lm
OBJ = $(BIN)main.o $(BIN)difficulty.o $(BIN)grid.o $(BIN)hint.o $(BIN)IGraph.o $(BIN)mines.o $(BIN)solver.o
OPT = -O2
INCLUDE = include/
SRC = src/
BIN = bin/
MKDIR_P = mkdir -p

# Definition des commandes a effectuer
$(BIN)$(EXEC) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(BIN)main.o : $(SRC)main.c $(INCLUDE)difficulty.h $(INCLUDE)grid.h $(INCLUDE)hint.h $(INCLUDE)IGraph.h $(INCLUDE)mines.h $(INCLUDE)solver.h

$(BIN)grid.o : $(SRC)grid.c $(INCLUDE)grid.h $(INCLUDE)difficulty.h $(INCLUDE)mines.h

$(BIN)mines.o : $(SRC)mines.c $(INCLUDE)mines.h $(INCLUDE)difficulty.h

$(BIN)IGraph.o : $(SRC)IGraph.c $(INCLUDE)IGraph.h $(INCLUDE)grid.h $(INCLUDE)mines.h $(INCLUDE)solver.h

$(BIN)solver.o : $(SRC)solver.c $(INCLUDE)solver.h $(INCLUDE)difficulty.h $(INCLUDE)grid.h $(INCLUDE)mines.h

$(BIN)difficulty.o : $(SRC)difficulty.c $(INCLUDE)difficulty.h

$(BIN)hint.o : $(SRC)hint.c $(INCLUDE)hint.h

$(BIN)%.o: $(SRC)%.c
	mkdir -p $(BIN)
	$(CC) -c $< $(CFLAGS) $(LDFLAGS) $(OPT) -o $@


# Définition des commandes de nettoyage
clean :
	rm -f $(BIN)*.o

mrproper : clean
	rm -f $(BIN)$(EXEC)
