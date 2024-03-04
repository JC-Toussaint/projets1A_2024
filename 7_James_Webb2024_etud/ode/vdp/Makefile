# Makefile du Projet: ode
#
CC   = gcc -g -std=c99
OBJ  = ode_vdp_rk45.o
LIBS =  -L/usr/X11R6/lib -lX11 -L $(HOME)/extralib/lib -lg2 -lgsl -lgslcblas -lm

INCS =  -I/usr/X11R6/include -I$(HOME)/extralib/include
BIN  = ode

all:  $(BIN)

clean:
	rm -f $(OBJ) $(BIN) *.o

$(BIN): $(OBJ)
	$(CC) $(INCS) $(OBJ) -o $(BIN) $(LIBS)

.c.o:
	$(CC) $(INCS) -c $<

