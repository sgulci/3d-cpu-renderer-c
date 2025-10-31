bar:
	gcc -Wall -lSDL2 -std=c99 src/*.c -o renderer  && ./renderer

clean:
	rm -rf renderer