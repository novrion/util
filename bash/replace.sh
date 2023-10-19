#!bin/bash
tmp=$(cat $1 | tr -d " \n\t")
echo $tmp > $1
