# Makefile du Projet: graph
#
CC   = gcc -g
OBJ  = main.o InitGraph.o Draw.o Animate.o Rebound.o gfx.o
LIBS =  -L/usr/X11R6/lib -lX11 -lXext -lm

INCS =  -I. -I/usr/X11R6/include -I$(HOME)/extralib/include
BIN  = graph2

all:  $(BIN)

clean:
	rm -f $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(INCS) $(OBJ) -o $(BIN) $(LIBS)

.c.o:
	$(CC) $(INCS) -c $<

