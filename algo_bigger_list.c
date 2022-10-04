/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bigger_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:20:37 by vjean             #+#    #+#             */
/*   Updated: 2022/10/04 14:57:46 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	finding_median(t_stack **stack_a)
{
	int	median;

	median = lstsize(*stack_a) / 2;
	return (median);
}

void	move_almost_all_in_b(t_stack **stack_a, t_stack **stack_b)
{
	while ((lstsize(*stack_a) >= 3)
	{
		if ((*stack_a)->index < finding_median(stack_a))
			do_pb(stack_a, stack_b);
		else
			do_ra(stack_a);
	}
}
// ^ boucle infini dans cette fonction... Try to fix it tomorrow