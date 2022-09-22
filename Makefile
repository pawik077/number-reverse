TARGET=.
OBJ=./obj
FLAGS=-Wall -Wextra -Werror -pedantic -std=c99 -g

__start__: $(TARGET)/numRev
	$(TARGET)/numRev

$(TARGET)/numRev: $(OBJ)/numRev.o
	gcc -o $(TARGET)/numRev $(OBJ)/numRev.o

$(OBJ):
	mkdir -p $(OBJ)

$(OBJ)/numRev.o: src/numRev.c
	gcc -c $(FLAGS) -o $(OBJ)/numRev.o src/numRev.c

clear:
	rm -f $(OBJ)/*.o