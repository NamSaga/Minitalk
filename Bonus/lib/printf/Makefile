NAME = libftprintf.a

SRCS = ft_printf.c ft_print_pointer.c ft_putchar.c ft_putnbr.c ft_putnbup.c ft_putstr.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBC = ar rcs

RM = rm -f

INC = include\ft_printf.h

.c.o: 
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INC}

${NAME}: ${OBJS}
		@${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean: 
		@${RM} ${OBJS}

fclean: clean
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re .c.o
