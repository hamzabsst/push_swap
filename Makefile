C = cc
CFLAGS = -Wall -Werror -Wextra

NAME = stack

MYLIB_DIR = mylib
MYLIB = mylib/myLib.a

SRCS =

OBJS = $(SRCS:.c=.o)

all: $(MYLIB) $(NAME)

$(MYLIB):
		@$(MAKE) -C mylib

%.o: %.c inc/stack.h
		@$(C) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJS) $(MYLIB)
		@$(C) $(CFLAGS) $(OBJS) $(MYLIB) -o $(NAME)

clean:
		@rm -f $(OBJS)
		@$(MAKE) clean -C $(MYLIB_DIR)

fclean: clean
		@rm -f $(NAME)
		@$(MAKE) fclean -C $(MYLIB_DIR)

re: fclean all

.PHONY: all clean fclean re
