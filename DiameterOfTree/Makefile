CC=clang++
CFLAGS=-I.
DEPS = Tree.h
OBJ = Tree.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tree_diameter: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o tree_diameter
