/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_about_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:22:20 by vjean             #+#    #+#             */
/*   Updated: 2022/10/07 14:59:08 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		size_a;
	int		size_b;

	head_a = *stack_a;
	head_b = *stack_b;
	size_a = lstsize(*stack_a);
	size_b = lstsize(*stack_b);
	while (*stack_b)
	{
		(*stack_b)->cost_b = (*stack_b)->pos_a;
		if ((*stack_b)->pos_b > (size_b / 2))
			(*stack_b)->cost_b = (size_b - (*stack_b)->pos_b) * -1;
		(*stack_b)->cost_a = (*stack_b)->target_pos;
		if ((*stack_b)->pos_b > (size_a / 2))
			(*stack_b)->cost_a = (size_a)
}
// ^ relire et revoir en détails.
}

void	check_only_three_in_a(t_stack **stack_a, t_stack **stack_b)
{
	while (lstsize(*stack_a) > 3)
		do_pb(stack_a, stack_b);
}

/*void	compare_cost(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->cost_b >= 0)
		do_rb;
	else
		do_rrb;
}*/
