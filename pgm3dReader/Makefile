CC=c++ 
CFLAGS=-std=c++11
EXEC=image3D
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

image3D: image3D.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXEC)
