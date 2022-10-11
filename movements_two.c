/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:05:29 by vjean             #+#    #+#             */
/*   Updated: 2022/10/11 14:41:40 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstlast(t_stack *stack_a)
{
	while (stack_a)
	{
		stack_a = stack_a->next;
		if (stack_a->next == NULL)
			return (stack_a);
	}
	return (stack_a);
}

void	do_ra(t_stack **stack_a, int i)
{
	t_stack	*last;

	last = lstlast(*stack_a);
	last->next = *stack_a;
	*stack_a = (*stack_a)->next;
	last->next->next = NULL;
	if (i == 0)
		write(1, "ra\n", 3);
}

void	do_rb(t_stack **stack_b, int i)
{
	t_stack	*last;

	last = lstlast(*stack_b);
	last->next = *stack_b;
	*stack_b = (*stack_b)->next;
	last->next->next = NULL;
	if (i == 0)
		write(1, "rb\n", 3);
}

void	do_rr(t_stack **stack_a, t_stack **stack_b, int i)
{
	do_ra(stack_a, i);
	do_rb(stack_b, i);
	if (i == 1)
		write(1, "rr\n", 3);
}

