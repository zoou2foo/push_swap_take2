/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:05:29 by vjean             #+#    #+#             */
/*   Updated: 2022/09/29 14:02:18 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstlast(t_stack **stack_a)
{
	while (*stack_a)
	{
		*stack_a = (*stack_a)->next; //doesn't go there;
		if ((*stack_a)->next == NULL)
			return (*stack_a);
	}
	return (*stack_a);
}

void	do_ra(t_stack **stack_a)
{
	t_stack	*last;

	last = lstlast(stack_a);
	last->next = *stack_a;
	*stack_a = (*stack_a)->next;
	last->next->next = NULL;
}

void	do_rb(t_stack **stack_b)
{
	t_stack	*last;

	last = lstlast(stack_b);
	last->next = *stack_b;
	*stack_b = (*stack_b)->next;
	last->next->next = NULL;
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	do_ra(stack_a);
	do_rb(stack_b);
}
