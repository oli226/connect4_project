compiler = gcc
dependencies = lib.h menu.h
objects = main.o lib.o menu.o

%.o: %.c $(dependencies)
	$(compiler) -c -o $@  $< -lncurses

connect4: $(objects)
	$(compiler) -o $@  $^ -lncurses

.PHONY = clean

clean:
	rm -rf *.o connect4
