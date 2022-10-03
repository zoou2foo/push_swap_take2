/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_short_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:31:00 by vjean             #+#    #+#             */
/*   Updated: 2022/10/03 15:02:22 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_how_many(t_stack **stack_a)
{
	if (lstsize(*stack_a) == 2)
		algo_for_two(stack_a);
	if (lstsize(*stack_a) == 3)
		algo_for_three(stack_a);
//	if (lstsize(*stack_a) > 3)
//		algo_for_bigger_list(&stack_a);
}

void	algo_for_two(t_stack **stack_a)
{
	if (check_if_sorted_for_two(*stack_a) == 0)
		return ;
	else if (check_if_sorted_for_two(*stack_a) == 1)
		do_sa(stack_a);
}

int	check_if_sorted_for_two(t_stack *stack_a)
{
	if (stack_a->next != NULL && stack_a->value < stack_a->next->value)
		return (0);
	return (1);
}

void	algo_for_three(t_stack **stack_a)
{
	find_pos_a(*stack_a);
	if (check_if_sorted(*stack_a) == 0)
		return ;
	else if (check_if_sorted(*stack_a) == 1)
	{
		if ((*stack_a)->pos_a == 0 && (*stack_a)->index == 2)
		{
			do_ra(stack_a);
			if ((*stack_a)->index > (*stack_a)->next->index)
				do_sa(stack_a);
		}
		else if ((*stack_a)->next->pos_a == 1 && (*stack_a)->next->index == 2)
		{
			do_rra(stack_a);
			if ((*stack_a)->index > (*stack_a)->next->index)
				do_sa(stack_a);
		}
	}
}

// segfault dans le if après rra... la stack_a serait vide.