#!/bin/bash

LIBFTDIR=..
LIBFTPRINTF=${LIBFTDIR}/libftprintf.a

if [ "$1" == "bonus" ]; then
	BONUS="-D BONUS"
	make bonus -C $LIBFTDIR
else
	make -C $LIBFTDIR
fi

# define
THICK="\033[1m"
CYAN="\033[1;36m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
RESET="\033[m"

if [ ! -e ${LIBFTPRINTF} ]; then
	printf "${YELLOW}Fatal: libftprintf.a not found. Please check the path\n${RESET}"
	exit
fi

gcc -Wall -Wextra -Werror ${BONUS} main.c ${LIBFTPRINTF} -o ft_printf
if [ $? != 0 ]; then
	printf "${YELLOW}Fatal: compilation failed. Please check dependencies\n${RESET}"
	exit
fi

./ft_printf > log_act
gcc -Wall -Wextra -Werror ${BONUS} -D REAL main.c -o printf
if [ $? != 0 ]; then
	printf "${YELLOW}Error: wrong usage of printf. Might effect to the output\n${RESET}"
fi
./printf > log_exp

diff -y log_act log_exp
if [ $? == 0 ]; then
	printf "${GREEN}[ Perfect! :) ]\n${RESET}"
else
	printf "${RED}[ Diff Found :( ]\n${RESET}"
fi

