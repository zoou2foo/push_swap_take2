/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:54:36 by vjean             #+#    #+#             */
/*   Updated: 2022/10/11 09:02:58 by vjean            ###   ########.fr       */
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
	write(1, "pb", 2);
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
	write(1, "pa", 2);
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
	write(1, "sa", 2); //besoin de revoir pour pas écrire 2 fois
}

void	do_sb(t_stack **stack_b)
{
	int	number;

	number = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = number;
	write(1, "sb", 2); //besoin de revoir pour pas écrire 2 fois
}
//for sb might need to adjust the position cible pour b

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	do_sa(stack_a);
	do_sb(stack_b);
}
//besoin de ne pas écrire sa et sb. Il faut juste que ça écrit ss