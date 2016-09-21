#!/bin/bash

DIR=$1
TTY=$2
clear
printf " \e[36m[ Compiling...]\n\n\e[0m"
make re
sleep 1
#$MAX = ll $DIR | wc -l
$COUNT = 0

for FILE in $( ls $DIR)
do
	printf "\n \e[36m[ Running... ]\n\n\e[33m"
	printf "\e[2J\e[0;0H\e[90m[\e[32m$COUNT\e[90m / \e[33m32\e[90m]\e[0m\n\e[90m[ $FILE ]\e[0m\n" >> $TTY
	let "COUNT++"
	time ./fdf $DIR/$FILE
	printf "<\n \e[34m[ END ]\n\n\e[33m"
done
