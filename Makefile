SRCDIR	= ./srcs/
SRCS	= ${wildcard ${SRCDIR}/*.c}
OBJDIR	= ${SRCDIR}
OBJS	= ${SRCS:.c=.o}
INCLUDE	= -I./includes
NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= AR
ARFLAGS	= rc
RM		= rm -f

all		:	${NAME}

.c.o	:
			${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}	:	${OBJS}
			${AR} ${ARFLAGS} ${NAME} ${OBJS}

clean	:
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}

re		: fclean all

.PHONY	: all clean fclean re
