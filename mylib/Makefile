CFLAGS = -Wall -Wextra -Werror
CC = cc

NAME = myLib.a

FILES = $(wildcard *.c)

SRCS =	$(FILES)

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
		ar rc ${NAME} ${OBJS}

%.o: %.c libft.h
		${CC} ${CFLAGS} -c $< -o $@

clean:
		@rm -f ${OBJS}

fclean: clean
		@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
