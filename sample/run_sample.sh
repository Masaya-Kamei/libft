#!/bin/zsh

LIBFT_INCLUDE_DIR=../
LIBFT_DIR=../

make -C ${LIBFT_DIR}
gcc main.c -I${LIBFT_INCLUDE_DIR} -L${LIBFT_DIR} -lft
echo "\n---sample---"
./a.out
