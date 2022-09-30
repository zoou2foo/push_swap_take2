/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:41:49 by vjean             #+#    #+#             */
/*   Updated: 2022/09/30 09:55:42 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstadd_front(t_stack **stack_a, t_stack *head)
{
	if (!stack_a)
		return (*stack_a);
	head->next = *stack_a;
	*stack_a = head;
	return (*stack_a);
}

void	do_rra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*old_head;
	t_stack	*new_head;
	int		size;
	int		i = 1;

	old_head = *stack_a;
	size = lstsize(old_head);
	printf("let's do this rra shit\n");
	last = lstlast(old_head);
	new_head = last;
	last->next = old_head;
	while (i < size)
	{
		//old_head = old_head->next;
		last = last->next;
		i++;
	}
	last->next = NULL;
	*stack_a = new_head;
	print_lst(stack_a);
}
//stack_a devient stack_a->next. Puis, le dernier devient le premier.