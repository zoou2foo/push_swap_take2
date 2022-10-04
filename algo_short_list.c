/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_short_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:31:00 by vjean             #+#    #+#             */
/*   Updated: 2022/10/04 14:52:44 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack **stack_b
void	check_how_many(t_stack **stack_a, t_stack **stack_b)
{
	(*stack_a)->size_max = lstsize(*stack_a);
	if ((*stack_a)->size_max == 2)
		algo_for_two(stack_a);
	if ((*stack_a)->size_max == 3)
		algo_three_versa(stack_a);
	if ((*stack_a)->size_max > 3)
		move_almost_all_in_b(stack_a, stack_b);
}

void	algo_for_two(t_stack **stack_a)
{
	if (check_if_sorted_for_two(*stack_a) == 0)
		return ;
	else if (check_if_sorted_for_two(*stack_a) == 1)
		do_sa(stack_a);
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

void	algo_three_versa(t_stack **stack_a)
{
	find_pos_a(*stack_a);
	if (check_if_sorted(*stack_a) == 0)
		return ;
	else if (check_if_sorted(*stack_a) == 1)
	{
		if ((*stack_a)->index == find_bigger_index(*stack_a))
		{
			do_ra(stack_a);
			if ((*stack_a)->index > (*stack_a)->next->index)
				do_sa(stack_a);
		}
		else if ((*stack_a)->next->index == find_bigger_index(*stack_a))
		{
			do_rra(stack_a);
			if ((*stack_a)->index > (*stack_a)->next->index)
				do_sa(stack_a);
		}
	}
}
