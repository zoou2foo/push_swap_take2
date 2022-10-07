/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_all_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:54:19 by vjean             #+#    #+#             */
/*   Updated: 2022/10/07 12:09:01 by vjean            ###   ########.fr       */
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

int	check_if_sorted_for_two(t_stack *stack_a)
{
	if (stack_a->next != NULL && stack_a->value < stack_a->next->value)
		return (0);
	return (1);
}

int	find_bigger_index(t_stack *stack_a)
{
	int		temp;
	t_stack	*head;

	temp = 0;
	head = stack_a;
	while (stack_a)
	{
		if (stack_a->index > temp)
			temp = stack_a->index;
		stack_a = stack_a->next;
	}
	stack_a = head;
	return (temp);
}

t_stack	*find_node_w_lower_index(t_stack *stack_a)
{
	int		temp;
	t_stack	*head;
	t_stack	*compare;

	temp = INT_MAX;
	head = stack_a;
	while (stack_a)
	{
		if (stack_a->index < temp)
		{
			compare = stack_a;
			temp = stack_a->index;
		}
		stack_a = stack_a->next;
	}
	stack_a = head;
	printf("la node avec l'index le plus petit: %d\n", compare->value);
	return (compare);
}
