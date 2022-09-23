/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:26:43 by vjean             #+#    #+#             */
/*   Updated: 2022/09/23 11:50:15 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack{
	int				value;
	int				index;
	int				size_max;
	int				pos_a;
	int				pos_b;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// value: nombre à trier
// index: son index dans toute la liste à trier
// size_max: savoir le nombre total d'éléments à trier
// pos_a: position actuelle dans la pile de A
// pos_b: position actuelle dans la pile de B
// target_pos: position cible dans la pileA (quand dans la pileB)
// cost_a: combien actions pour faire pivoter A (pour aller au sommet de A)
// cost_b: combien actions pour faire pivoter B (pour aller au sommet de B)
// next: pointeur pour le prochain élément

/* check arguments */
void	is_alpha(char **av);
void	check_numbers(char **av);
int		check_doubles(t_stack **stack_a);

/* to deal with linked list */
void	fill_lst(char **av, t_stack **stack_a);
void	check_if_sorted(t_stack **stack_a);
void	setup_index(t_stack **stack_a);
//int		lstsize(t_stack **stack_a);

/* all about the movements */
void	do_pb(t_stack **stack_a);

/* Yeah I'm free! Free fallin'!! */
void	free_node(t_stack **stack_a);

/* useless functions. Just to help me */
void	print_split(char **av);

#endif
