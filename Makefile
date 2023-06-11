CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -g
LFLAGS = -lGL -lGLU -lglut

ex15: main.o
	$(CC) $^ $(LFLAGS) -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f ex15 *.o
