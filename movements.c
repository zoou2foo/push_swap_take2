/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:54:36 by vjean             #+#    #+#             */
/*   Updated: 2022/09/28 13:39:32 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;

	head_a = *stack_a;
	*stack_a = (*stack_a)->next;
	head_a->next = *stack_b; //amène 1erang stackb au 2e rang stackb
	*stack_b = head_a; //maillon déplacé
	/*printf("valeur à la head_a: %d\n", head_a->value);
	printf("valeur à la stack_a: %d\n", (*stack_a)->value);
	printf("valeur à la stack_b: %d\n", (*stack_b)->value);*/
}

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_b;

	head_b = *stack_b;
	*stack_b = (*stack_b)->next;
	head_b->next = *stack_a;
	*stack_a = head_b;
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
}

void	do_sb(t_stack **stack_b)
{
	int	number;

	number = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = number;
}
//for sb might need to adjust the position cible pour b

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	do_sa(stack_a);
	do_sb(stack_b);
}
//besoin de ne pas écrire sa et sb. Il faut juste que ça écrit ss