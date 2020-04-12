a.exe: main.o pregame.o game.o postgame.o
	gcc -o a main.o pregame.o game.o postgame.o

main.o: main.c root.h
	gcc -Wall -g -c main.c

pregame.o: pregame.c root.h
	gcc -Wall -g -c pregame.c

game.o: game.c root.h
	gcc -Wall -g -c game.c

postgame.o: postgame.c root.h
	gcc -Wall -g -c postgame.c

clean:
	del a.exe main.o pregame.o game.o postgame.o