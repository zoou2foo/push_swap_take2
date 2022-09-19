/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:26:43 by vjean             #+#    #+#             */
/*   Updated: 2022/09/19 14:47:33 by vjean            ###   ########.fr       */
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
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_info{
	int				size_max;
	int				pos_a;
	int				pos_b;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	t_stack			*head_a;
	t_stack			*head_b;
}	t_info;

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
void	check_numbers(char **av, t_info *info);

/* to deal with linked list */
void	add_lst(t_info *info, t_stack *temp);
t_stack	*lst_last(t_info *info);
t_stack	*lst_new(int temp);

/* useless functions. Just to help me */
void	print_split(char **av);

#endif