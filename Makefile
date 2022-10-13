 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjean <vjean@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 14:52:28 by vjean             #+#    #+#              #
#    Updated: 2022/10/11 13:43:43 by vjean            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c check_args.c create_n_deal_list.c movements.c\
		movements_two.c movements_three.c setup_all_index.c algo_short_list.c\
		algo_bigger_list.c all_about_cost.c set_moves.c \
# nom des fichiers sources

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc #le compilateur à utiliser

CFLAGS = -g -Wall -Wextra -Werror

ARGS = 778 34 1 89 
#ARGS = "778 34 1 89" 

.c.o:
		@$(CC)$(CFLAGS) -c $< -o $(<:.c=.o)

#AR = ar rcs

RM = rm -fr

#BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	cd libft && make
		@$(CC) $(OBJS) $(LIBFT) -o $(NAME)
exec: $(NAME)
	valgrind --leak-check=full ./push_swap $(ARGS)

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