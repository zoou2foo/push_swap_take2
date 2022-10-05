/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bigger_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:20:37 by vjean             #+#    #+#             */
/*   Updated: 2022/10/05 14:07:47 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finding_pos(t_stack *stack_a, t_stack *stack_b)
{
	find_pos_a(stack_a);
	find_pos_b(stack_b);
}

int	finding_median(t_stack **stack_a)
{
	int	median;

	median = lstsize(*stack_a) / 2;
	return (median);
}

void	move_almost_all_in_b(t_stack **stack_a, t_stack **stack_b)
{
	while ((lstsize(*stack_a) > 3))
	{
		if ((*stack_a)->index < finding_median(stack_a))
			do_pb(stack_a, stack_b);
		else
			do_ra(stack_a);
	}
}

void	find_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = *stack_a;
	head_b = *stack_b;
	while (*stack_a)
	{
		while (*stack_b)
		{
			if ((*stack_a)->index > (*stack_b)->index)
				(*stack_a)->pos_a = (*stack_b)->target_pos;
			*stack_b = (*stack_b)->next;
		}
		*stack_a = (*stack_a)->next;
	}
	*stack_a = head_a;
	*stack_b = head_b;
}

void	do_algo_more_three(t_stack **stack_a)
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
	else if ((*stack_a)->index > (*stack_a)->next->index)
		do_sa(stack_a);
}
