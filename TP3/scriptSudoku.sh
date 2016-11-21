#!/bin/bash

rm ResultatSudoku.cnf
rm ResultatMinisat.txt

./sudoku 
minisat ResultatSudoku.cnf ResultatMinisat.txt
./SudokuAffichage
cat ResultatFinal.txt
echo ""
