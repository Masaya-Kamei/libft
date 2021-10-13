# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 18:28:14 by mkamei            #+#    #+#              #
#    Updated: 2021/10/13 17:14:58 by mkamei           ###   ########.fr        #
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

LIBFTDIR		:= ../
LIBFTNAME 		:= ft
LIBFTINCLUDEDIR := ../

LIBUNITDIR		:= framework
LIBUNITNAME 	:= unit
LIBUNITINCLUDEDIR:= framework

LIBINCLUDE	:= -I${LIBFTINCLUDEDIR} -I${LIBUNITINCLUDEDIR}
LIBDIR		:= -L${LIBFTDIR} -L${LIBUNITDIR}
LIBLINK		:= -l${LIBFTNAME} -l${LIBUNITNAME}
ifeq ($(shell uname),Linux)
	LIBLINK	+= -lbsd
endif
LIB			:= $(LIBINCLUDE) $(LIBDIR) $(LIBLINK)

LIBFTTARGET	:= all
LIBFT		:= $(LIBFTDIR)/libft.a

all		:	$(NAME)

$(NAME)	:	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIB) -o $@

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDE) $(LIBINCLUDE) -o $@ -c $<

$(LIBFT):
			make $(LIBFTTARGET) -C $(LIBFTDIR)

test	:	$(NAME)
			@./$(NAME) || :

clean	:
			$(RM) $(OBJS)
			make clean -C $(LIBFTDIR)

fclean	: 	clean
			$(RM) $(NAME)
			make fclean -C $(LIBFTDIR)

re		:	fclean all

address	:	LIBFTTARGET	=	address
address	:	CC			=	clang
address	:	CFLAGS 		+= 	-g -fsanitize=address
address	:	re

leak	:	LIBFTTARGET	=	leak
leak	:	CC			=	clang
leak	:	CFLAGS 		+= 	-g -fsanitize=leak
leak	:	re

.PHONY	:	all clean fclean re address leak
