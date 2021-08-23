#!/bin/bash

LIBFTPRINTF=../libftprintf.a

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

gcc -Wall -Wextra -Werror main.c ${LIBFTPRINTF} -o ft_printf
./ft_printf > log_act
gcc -Wall -Wextra -Werror -D REAL main.c -o printf
./printf > log_exp

diff log_act log_exp
if [ $? == 0 ]; then
	printf "${GREEN}OK :)\n${RESET}"
else
	printf "${RED}KO :(\n${RESET}"
fi

