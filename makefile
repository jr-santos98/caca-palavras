CC = gcc
CFLAGS = -g -pthread

PROGRAMS = th-caca-palavras caca-palavras

all: $(PROGRAMS)

clean:
	rm -f *~ $(PROGRAMS)
