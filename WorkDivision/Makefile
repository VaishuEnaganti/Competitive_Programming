CC=clang++
CFLAGS=-I.
DEPS = work_partition.h
OBJ = work_partition.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

work_partition: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o work_partition
