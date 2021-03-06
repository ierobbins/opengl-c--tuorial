
GL_H = /usr/include/GL
GL_L = libglew-dev

SDL_H = /usr/include/SDL2
SDL_L = libsdl2-dev

CFLAGS = `sdl2-config --cflags --libs` -std=gnu++11

run: main.o display.o shader.o mesh.o stb_image.o texture.o
	g++ main.o display.o shader.o mesh.o stb_image.o texture.o -L $(CFLAGS) -lGL -lGLEW -o driver

main.o: main.cpp
	g++ -c main.cpp -I $(GL_H)

display.o: display.cpp display.h
	g++ -c display.cpp -I $(SDL_H)

shader.o: shader.cpp shader.h
	g++ -c shader.cpp -I $(GL_H)

mesh.o: mesh.cpp mesh.h
	g++ -c mesh.cpp -I $(GL_H)

stb_image.o: stb_image.c stb_image.h
	gcc -c stb_image.c

texture.o: texture.cpp texture.h
	g++ -c texture.cpp -I $(GL_H)

clean:
	rm *.o driver
