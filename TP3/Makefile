# Makefile (règles implicites)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o

tout: kernel sudoku SudokuAffichage

kernel:kernel.c
	$(CC) $(CFLAGS) kernel kernel.c
	
sudoku:sudoku.c
	$(CC) $(CFLAGS) sudoku sudoku.c
	
SudokuAffichage:SudokuAffichage.c
	$(CC) $(CFLAGS) SudokuAffichage SudokuAffichage.c

clean:
	rm *.o 
