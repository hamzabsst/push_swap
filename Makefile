CC = cc
CFLAGS = -Wall -Werror -Wextra

MYLIB_DIR = mylib
MYLIB = $(MYLIB_DIR)/myLib.a

NAME = push_swap

SRCS = src/init_stack.c \
		src/main.c \
		src/check_errors.c \
		src/stack_utils.c \
		src/stack_utils1.c \
		src/commands/push.c \
		src/commands/r_rotate.c \
		src/commands/rotate.c \
		src/commands/swap.c \
		src/sorting/tiny_sorts.c \
		src/sorting/sort_stack.c \

OBJS = $(SRCS:.c=.o)

all: $(MYLIB) $(NAME)

$(MYLIB):
		@$(MAKE) -C $(MYLIB_DIR)

%.o: %.c inc/push_swap.h
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(MYLIB)
		@$(CC) $(CFLAGS) $(OBJS) $(MYLIB) -o $(NAME)

clean:
		@rm -f $(OBJS)
		@$(MAKE) clean -C $(MYLIB_DIR)

fclean: clean
		@rm -f $(NAME)
		@$(MAKE) fclean -C $(MYLIB_DIR)

re: fclean all

.PHONY: all clean fclean re
