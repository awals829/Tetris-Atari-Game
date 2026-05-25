test: psg.o effects.o music.o test.o
	cc68x -g psg.o effects.o music.o test.o -o test

psg.o: psg.c psg.h
	cc68x -g -c psg.c

effects.o: effects.c effects.h
	cc68x -g -c effects.c

music.o: music.c music.h
	cc68x -g -c music.c

test.o: test.c test.h
	cc68x -g -c test.c

