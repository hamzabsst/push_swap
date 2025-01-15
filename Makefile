CC = cc
CFLAGS = -Wall -Werror -Wextra

MYLIB_DIR = mylib
MYLIB = $(MYLIB_DIR)/myLib.a

NAME = push_swap
NAME_BONUS = checker

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

SRCS_BONUS = bonus/checker_bonus.c \
				bonus/utils_bonus.c \
				bonus/utils_bonus1.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(MYLIB) $(NAME)

$(MYLIB):
		@$(MAKE) -C $(MYLIB_DIR)

%.o: %.c inc/push_swap.h
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(MYLIB)
		@$(CC) $(CFLAGS) $(OBJS) $(MYLIB) -o $(NAME)

OBJS_NO_MAIN = $(filter-out src/main.o, $(OBJS))

$(NAME_BONUS): $(OBJS_BONUS) $(OBJS_NO_MAIN) $(MYLIB)
		$(CC) $(CFLAGS) $(OBJS_BONUS) $(OBJS_NO_MAIN) $(MYLIB) -o $(NAME_BONUS)
		@touch $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
		@rm -f $(OBJS) $(OBJS_BONUS)
		@$(MAKE) clean -C $(MYLIB_DIR)

fclean: clean
		@rm -f $(NAME) $(NAME_BONUS)
		@$(MAKE) fclean -C $(MYLIB_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
