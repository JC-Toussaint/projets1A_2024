# Makefile du Projet: projet
#
CC   = gcc -g -std=gnu11

BIN  = projet
LIBS =  -L/usr/X11R6/lib -lX11 -lXext -L $(HOME)/extralib/lib -lgsl -lgslcblas -lm
INCS =  -I. -I/usr/X11R6/include -I$(HOME)/extralib/include

SOURCES := $(wildcard *.c)
OBJECTS := $(patsubst %.c,%.o,$(SOURCES))
DEPENDS := $(patsubst %.c,%.d,$(SOURCES))

# ADD MORE WARNINGS!
WARNING := -Wall -Wextra

# .PHONY means these rules get executed even if
# files of those names exist.
.PHONY: all clean

# The first rule is the default, ie. "make" and "make all" mean the same here
all:  $(BIN)

clean:
	rm -f $(OBJECTS) $(DEPENDS) $(BIN)

# Linking the executable from the object files
$(BIN): $(OBJECTS)
	$(CC) $(INCS) $(WARNING) $(CFLAGS) $^ -o $@ $(LIBS)

-include $(DEPENDS)

%.o: %.c Makefile
	$(CC) $(INCS) $(WARNING) $(CFLAGS) -MMD -MP -c $< -o $@
