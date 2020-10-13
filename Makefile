SRCDIR	= ./srcs/
SRCS	= ${wildcard ${SRCDIR}/ft_m*.c ${SRCDIR}/ft_b*.c ${SRCDIR}/ft_s*.c ${SRCDIR}/ft_a*.c}
SRCS	+= ${wildcard ${SRCDIR}/ft_i*.c ${SRCDIR}/ft_t*.c ${SRCDIR}/ft_c*.c ${SRCDIR}/ft_p*.c}
B_SRCS	= ${SRCS} ${wildcard ${SRCDIR}/ft_lst*.c}
OBJDIR	= ${SRCDIR}
OBJS	= ${SRCS:.c=.o}
B_OBJS	= ${B_SRCS:.c=.o}
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

bonus	:	${B_OBJS}
			${AR} ${ARFLAGS} ${NAME} ${B_OBJS}

clean	:
			${RM} ${B_OBJS}

fclean	:	clean
			${RM} ${NAME}

re		: fclean all

.PHONY	: all clean fclean re bonus
