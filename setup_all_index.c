/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_all_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:54:19 by vjean             #+#    #+#             */
/*   Updated: 2022/10/03 10:52:01 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_pos_a(t_stack *stack_a)
{
	t_stack	*head;
	int		i;

	i = 0;
	head = stack_a;
	while (stack_a)
	{
		stack_a->pos_a = i;
		i++;
		stack_a = stack_a->next;
	}
	stack_a = head;
}
// ^ besoin de int i pour assigner une valeur à pos_a
// ^ pour CHAQUE node. Ainsi, la valeur de pos_a est changée
// ^ lorsque le i est incrémenté

void	find_pos_b(t_stack *stack_b)
{
	t_stack	*head_b;
	int		i;

	i = 0;
	head_b = stack_b;
	while (stack_b)
	{
		stack_b->pos_b = i;
		i++;
		stack_b = stack_b->next;
	}
	stack_b = head_b;
}

/*void	find_target_pos(t_stack *stack_b, t_stack *stack_a)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		i;

	i = 0;
	head_a = stack_a;
	head_b = stack_b;
	
}*/