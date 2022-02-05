# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 18:28:14 by mkamei            #+#    #+#              #
#    Updated: 2022/02/05 08:22:02 by mkamei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSNAME:=	main.c utils/utils.c $(wildcard testsrcs/*.c)
SRCSDIR	:=	.
SRCS	:=	$(addprefix $(SRCSDIR)/, $(SRCSNAME))

OBJSNAME:=	$(SRCSNAME:.c=.o)
OBJSDIR	:=	./objs
OBJS	:=	$(addprefix $(OBJSDIR)/, $(OBJSNAME))

INCLUDE	:=	-I./
NAME	:=	unit_test

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
RM		:=	rm -rf

LIBFTDIR		:=	../
LIBFTTARGET		:=	all
LIBFT			:=	$(LIBFTDIR)/libft.a

LIBUNITDIR		:=	./libunit
LIBUNITTARGET	:=	all
LIBUNIT			:=	$(LIBUNITDIR)/libunit.a

LIBINCLUDE		:=	-I../ -I./libunit/includes
LIBDIR			:=	-L${LIBFTDIR} -L${LIBUNITDIR}
LIBLINK			:=	-lft -lunit
LIB				:=	$(LIBINCLUDE) $(LIBDIR) $(LIBLINK)

all		:	$(NAME)

$(NAME)	:	$(LIBFT) $(LIBUNIT) $(OBJS)
			$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIB) -o $@

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDE) $(LIBINCLUDE) -o $@ -c $<

$(LIBFT):
			make $(LIBFTTARGET) -C $(LIBFTDIR)

$(LIBUNIT):
			make $(LIBUNITTARGET) -C $(LIBUNITDIR)

test	:	$(NAME)
			@./$(NAME) || :

clean	:
			$(RM) $(OBJS)
			make clean -C $(LIBFTDIR)
			make clean -C $(LIBUNITDIR)

fclean	: 	clean
			$(RM) $(NAME)
			make fclean -C $(LIBFTDIR)
			make fclean -C $(LIBUNITDIR)

re		:	fclean all

address	:	LIBFTTARGET		=	address
address	:	LIBUNITTARGET	=	address
address	:	CC				=	clang
address	:	CFLAGS 			+= 	-g -fsanitize=address
address	:	re

leak	:	LIBFTTARGET		=	leak
leak	:	LIBUNITTARGET	=	leak
leak	:	CC				=	/usr/local/opt/llvm/bin/clang
leak	:	CFLAGS 			+= 	-g -fsanitize=leak
leak	:	re

.PHONY	:	all clean fclean re address leak
