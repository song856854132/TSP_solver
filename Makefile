all:a.out
CC = g++
CFLAG = -Wall -g
DEPS = tsp.h
OBJ = tsp.o main.o
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAG) -c -o $@ $<
a.out: $(OBJ)
	$(CC) $(CFLAG) -o $@ $^
clean:
	rm *.o
