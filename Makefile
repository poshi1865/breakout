
CC=gcc
main: main.c draw.c paddle.c
	$(CC) -o main main.c paddle.c draw.c `sdl2-config --cflags --libs` -ggdb3 -O0 --std=c99 -Wall -lSDL2_image -g


