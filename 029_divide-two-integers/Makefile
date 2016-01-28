IDIR=.
CC=g++
CFLAGS=-I$(IDIR) -std=c++11
LDFLAGS=

ODIR=obj
LDIR=.
EXECUTABLE=a.out

LIBS=-L.

# FIXME
_DEPS=divide-two-integers.hh
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)

$(ODIR)/%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm $(ODIR)/*.o
