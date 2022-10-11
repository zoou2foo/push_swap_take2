/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:54:36 by vjean             #+#    #+#             */
/*   Updated: 2022/10/11 14:58:58 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;

	head_a = *stack_a;
	*stack_a = (*stack_a)->next;
	head_a->next = *stack_b;
	*stack_b = head_a;
	write(1, "pb\n", 3);
}
//head_a->next = *stack_b; amène 1erang stackb au 2e rang stackb
//	*stack_b = head_a; maillon déplacé

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_b;

	head_b = *stack_b;
	*stack_b = (*stack_b)->next;
	head_b->next = *stack_a;
	*stack_a = head_b;
	write(1, "pa\n", 3);
}

void	do_sa(t_stack **stack_a)
{
	int	number;

	number = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = number;
	number = (*stack_a)->index;
	(*stack_a)->index = (*stack_a)->next->index;
	(*stack_a)->next->index = number;
	write(1, "sa\n", 3);
}

void	do_sb(t_stack **stack_b)
{
	int	number;

	number = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = number;
	write(1, "sb\n", 3);
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	do_sa(stack_a);
	do_sb(stack_b);
}
