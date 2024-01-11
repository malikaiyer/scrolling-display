FLAVOR = nopi
INCLUDE = $(INCLUDE_NOPI)
LDFLAGS = $(LDFLAGS_NOPI)

INCLUDE_PI := -I ~/include
LDFLAGS_PI := -L ~/lib -lsense -lm
INCLUDE_NOPI :=
LDFLAGS_NOPI := -lncurses

all: scroll

scroll: main.o display.o input.o
	cc -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o scroll
main.o: main.c scroll.h
	cc -c $<
display.o: display.c scroll.h
	cc -o $@ -c $< $(INCLUDE)
input.o: input.c scroll.h
	cc -o $@ -c $< $(INCLUDE)

run:
	./scroll

remove:
	rm main.o
	rm input.o
	rm display.o
	rm scroll

