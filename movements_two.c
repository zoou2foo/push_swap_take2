/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:05:29 by vjean             #+#    #+#             */
/*   Updated: 2022/10/11 09:06:13 by vjean            ###   ########.fr       */
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

void	do_ra(t_stack **stack_a)
{
	t_stack	*last;

	last = lstlast(*stack_a);
	last->next = *stack_a;
	*stack_a = (*stack_a)->next;
	last->next->next = NULL;
	write(1, "ra", 2); //besoin de revoir pour pas écrire 2 fois ra
}

void	do_rb(t_stack **stack_b)
{
	t_stack	*last;

	last = lstlast(*stack_b);
	last->next = *stack_b;
	*stack_b = (*stack_b)->next;
	last->next->next = NULL;
	write(1, "rb", 2); //besoin de revoir pour pas écrire 2 fois rb
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	do_ra(stack_a);
	do_rb(stack_b);
}
// ^ besoin d'écrire rr
