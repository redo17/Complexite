#!/bin/bash


if [ $# -lt 3 ]
then
   echo "il faut mettre en argument le graphe"
   exit	
fi

rm ResultatFinal.txt
rm Resultat3Color.cnf
rm Resultatminisat.txt

./3color $*
minisat Resultat3Color.cnf Resultatminisat.txt
./coloriage
