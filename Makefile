jeux: main.o
	gcc  main.o -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -o jeux
main.o:main.c
	gcc -c main.c
