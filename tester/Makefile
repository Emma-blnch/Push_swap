NAME = push_swap
TESTER = tester

CC = cc
CFLAGS = -Wall -Wextra -Werror

ROOT_DIR = ..
LIBFT_DIR = $(ROOT_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
PUSH_SWAP_OBJS = $(ROOT_DIR)/srcs/ft_push_swap.o $(ROOT_DIR)/srcs/ft_push_swap_utils.o \
                 $(ROOT_DIR)/srcs/ft_push.o $(ROOT_DIR)/srcs/ft_swap.o \
				 $(ROOT_DIR)/srcs/ft_rotate.o \
                 $(ROOT_DIR)/srcs/ft_reverse_rotate.o $(ROOT_DIR)/srcs/ft_short_sort.o \
				 $(ROOT_DIR)/srcs/ft_sort_five.o

TEST_SRCS = tester.c
TEST_OBJS = $(TEST_SRCS:.c=.o)

all: $(LIBFT) $(PUSH_SWAP) $(TESTER)

$(PUSH_SWAP_OBJS):
	make -C $(ROOT_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(TESTER): $(TEST_OBJS) $(PUSH_SWAP_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(PUSH_SWAP_OBJS) -o $(TESTER) -L$(LIBFT_DIR) -lft

test: $(TESTER)
	./$(TESTER)

clean:
	rm -f $(TEST_OBJS)
	make clean -C $(ROOT_DIR)

flcean: clean
	rm -f $(TESTER)
	make fclean -C $(ROOT_DIR)

re: fclean all

.PHONY: all clean fclean re test
