# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 15:25:09 by eblancha          #+#    #+#              #
#    Updated: 2024/12/20 11:24:42 by eblancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIR = includes

SRCS = srcs/ft_init_and_choose.c srcs/ft_utils.c srcs/ft_short_sort.c srcs/ft_sort_five.c \
srcs/ft_sort_four.c srcs/ft_radix_sort.c srcs/ft_radix_utils.c srcs/ft_find_number.c \
srcs/ft_reverse_rotate.c srcs/ft_push.c srcs/ft_swap.c srcs/ft_rotate.c srcs/ft_main.c

OBJS = $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make clean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
