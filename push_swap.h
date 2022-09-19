/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:26:43 by vjean             #+#    #+#             */
/*   Updated: 2022/09/19 09:14:03 by vjean            ###   ########.fr       */
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
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// value: nombre à trier
// index: son index dans toute la liste à trier
// pos: position actuelle dans la pile
// target_pos: position cible dans la pileA (quand dans la pileB)
// cost_a: combien actions pour faire pivoter A (pour aller au sommet de A)
// cost_b: combien actions pour faire pivoter B (pour aller au sommet de B)
// next: pointeur pour le prochain élément
/* check arguments */
void	is_alpha(char **av);
void	check_numbers(char **av);

/* useless functions. Just to help me */
void	print_split(char **av);

#endif