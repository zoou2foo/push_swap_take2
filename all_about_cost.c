/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_about_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriejean <valeriejean@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:22:20 by vjean             #+#    #+#             */
/*   Updated: 2022/10/06 19:46:33 by valeriejean      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_cost_b(t_stack **stack_b)
{
	t_stack *head_b;
	
	head_b = *stack_b;
	while (*stack_b)
	{
		(*stack_b)->cost_b = 0;
		if ((*stack_b)->pos_b < lstsize(*stack_b))
			(*stack_b)->cost_b += 1;
		else
			(*stack_b)->cost_b -= 1;
		*stack_b = (*stack_b)->next;
	}
	*stack_b = head_b;
}

void	find_cost_a(t_stack **stack_a)
{
	t_stack *head_a;
	
	head_a = *stack_a;
	while (*stack_a)
	{
		(*stack_a)->cost_a = 0;
		if ((*stack_a)->pos_a < lstsize(*stack_a))
			(*stack_a)->cost_a += 1;
		else
			(*stack_a)->cost_a -= 1;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = head_a;
}

/*void	compare_cost(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->cost_b >= 0)
		do_rb;
	else
		do_rrb;
}*/
