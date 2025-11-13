RAYLIB = ../raylib/src/

all:
	gcc src/main.c -O3 -I $(RAYLIB) -L $(RAYLIB) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
