#---------------------------------compile------------------------------------#
CC = cc
CFLAGS = -Wall -Werror -Wextra

#------------------------------------lib-------------------------------------#
NAME = push_swap
MYLIB_DIR = mylib
MYLIB = $(MYLIB_DIR)/myLib.a

#---------------------------------sources------------------------------------#
SRCS = src/init_stack.c \
		src/main.c \

OBJS = $(SRCS:.c=.o)

all: $(MYLIB) $(NAME)

$(MYLIB):
		@$(MAKE) -C $(MYLIB_DIR)

%.o: %.c inc/push_swap.h
		@$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJS) $(MYLIB)
		@$(CC) $(CFLAGS) $(OBJS) $(MYLIB) -o $(NAME)

#---------------------------------clean--------------------------------------#

clean:
		@rm -f $(OBJS)
		@$(MAKE) clean -C $(MYLIB_DIR)

fclean: clean
		@rm -f $(NAME)
		@$(MAKE) fclean -C $(MYLIB_DIR)

re: fclean all

.PHONY: all clean fclean re
