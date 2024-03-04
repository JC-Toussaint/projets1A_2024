# Makefile du Projet: histo
#
CC   = gcc -g
OBJ  = histo.o
LIBS =  -L/usr/X11R6/lib -lX11 -L $(HOME)/extralib/lib -lg2 -lgsl -lgslcblas -lm

INCS =  -I/usr/X11R6/include -I$(HOME)/extralib/include
BIN  = histo

all:  $(BIN)

clean:
	rm -f $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(INCS) $(OBJ) -o $(BIN) $(LIBS)

.c.o:
	$(CC) $(INCS) -c $<

