PROJECT = lum_p1
CFLAGS = -Wall -Werror -g -std=c++14

.PHONY: all run clean memcheck

all: $(PROJECT)

$(PROJECT): $(PROJECT).cpp State.o
		g++ $(CFLAGS) $(PROJECT).cpp State.o -o $(PROJECT) 

State.o: State.cpp State.h	


run: $(PROJECT) all
		./$(PROJECT)

clean:
		rm -vf *.o $(PROJECT)

memcheck: all
		valgrind ./$(PROJECT)
