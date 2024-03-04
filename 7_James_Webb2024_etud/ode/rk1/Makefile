# Makefile du Projet: ode_rk1
#
CC   = gcc -g -std=c99
OBJ  = ode_rk1.o
LIBS =  -L/usr/X11R6/lib -lX11 -L $(HOME)/extralib/lib -lg2 -lm

INCS =  -I/usr/X11R6/include -I$(HOME)/extralib/include
BIN  = ode_rk1

all:  $(BIN)

clean:
	rm -f $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(INCS) $(OBJ) -o $(BIN) $(LIBS)

.c.o:
	$(CC) $(INCS) -c $<

