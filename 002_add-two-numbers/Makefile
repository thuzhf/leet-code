IDIR=.
CC=g++
CFLAGS=-I$(IDIR)
LDFLAGS=

ODIR=obj
LDIR=.
EXECUTABLE=a.out

LIBS=-L.

_DEPS=add-two-numbers.hpp
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm $(ODIR)/*.o
