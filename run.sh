#!/bin/bash
# Author: Miika Viinikainen

clear

test_files="./sources"
ft_printf="results/ft_printf_result.txt"
printf="results/printf_result.txt"

# Put your ft_printf path here

FT_PRINTF_DIR="YOUR PRINTF PATH HERE"
FT_PRINTF_DIR=~/workspace/ft_printf/

# Colors
red="\033[0;31m"
green="\033[0;32m"
yellow='\033[1;7;33m'
end="\033[0m"

# Make ft_printf #

echo "Making ft_printf"
make fclean -C $FT_PRINTF_DIR &> /dev/null
make -C $FT_PRINTF_DIR &> /dev/null

if [ $? == 0 ]
	then
		printf "Make ${green}success${end}\n"
		cp ../ft_printf/libftprintf.a .
else
	printf "Makefile ${red}failed${end}, can't continue tests.\n"
	exit
fi

sleep 2
# Loop through testfile and remove the unnecessary files at end#
printf "**********${yellow}PRINTF TESTS STARTS${end}**********\n"

sleep 3

mkdir results &> /dev/null

for file in "$test_files"/*
do
	
	gcc -w -g $file libftprintf.a
	./a.out
	diff_file="${file##*/}_diff.txt"
	diff $ft_printf $printf > $diff_file
	if [ -s $diff_file ]
		then
			printf "${file} test $red failed ${end}\n"
			mkdir failed &> /dev/null
			mv results/* failed/
			mv failed/${ft_printf##*/} failed/"${file##*/}"_fail_IM
			mv failed/${printf##*/} failed/"${file##*/}"_fail_OG
	else
		rm $diff_file &> /dev/null
		rm $ft_printf $printf
		printf "${diff_file%%.*} test ${green} succeeded ${end}\n"
	fi
	
	sleep 1
done

rm -fr results a.out libftprintf.a &> /dev/null

echo "End of test, see diff file for errors"

