# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 14:52:28 by vjean             #+#    #+#              #
#    Updated: 2022/09/20 09:22:39 by vjean            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c check_args.c create_n_deal_list.c \
# nom des fichiers sources

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc #le compilateur à utiliser

CFLAGS = -g -Wall -Wextra -Werror

.c.o:
	@$(CC)$(CFLAGS) -c $< -o $(<:.c=.o)

#AR = ar rcs

RM = rm -fr

#BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	cd libft && make
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)


clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

#bonus: $(OBJS) $(BONUS_OBJS)
#$(CC) $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re #bonus