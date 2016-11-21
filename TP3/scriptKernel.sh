#!/bin/bash

if [ $# -lt 3 ]
then
   echo "il faut mettre en argument le graphe"
   exit	
fi

rm ResultatKernel.cnf
rm ResultatMinisat.txt

./kernel $*
minisat ResultatKernel.cnf ResultatMinisat.txt
cat ResultatMinisat.txt
echo ""
