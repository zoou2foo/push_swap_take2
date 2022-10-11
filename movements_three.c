/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:41:49 by vjean             #+#    #+#             */
/*   Updated: 2022/10/11 14:50:58 by vjean            ###   ########.fr       */
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

void	do_rra(t_stack **stack_a, int j)
{
	t_stack	*last;
	t_stack	*old_head;
	t_stack	*new_head;
	int		size;
	int		i;

	i = 1;
	old_head = *stack_a;
	size = lstsize(old_head);
	if (size == 1)
		return ;
	last = lstlast(old_head);
	new_head = last;
	last->next = old_head;
	while (i < size)
	{
		last = last->next;
		i++;
	}
	last->next = NULL;
	*stack_a = new_head;
	if (j == 0)
		write(1, "rra\n", 4);
}
// ^ besoin de plusieurs nouvelles variables
// ^ last pour trouver le dernier node de la liste. Old_head qui représente
// ^ l'ancien pointeur/début de la liste. Puis, new_head représente le nouveau
// ^ pointeur/début de la liste avec le dernier node qui est en premier.
// ^ Un int pour déterminer la longueur de la liste pour être en mesure d'aller
// ^ récupérer le nouveau "dernier" node. Puis, un index pour parcourir la list
// ^ selon la size.

void	do_rrb(t_stack **stack_b, int j)
{
	t_stack	*last;
	t_stack	*old_head;
	t_stack	*new_head;
	int		size;
	int		i;

	i = 1;
	old_head = *stack_b;
	size = lstsize(old_head);
	if (size == 1)
		return ;
	last = lstlast(old_head);
	new_head = last;
	last->next = old_head;
	while (i < size)
	{
		last = last->next;
		i++;
	}
	last->next = NULL;
	*stack_b = new_head;
	if (j == 0)
		write(1, "rrb\n", 4);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b, int i)
{
	do_rra(stack_a, i);
	do_rrb(stack_b, i);
	if (i == 1)
		write(1, "rrr\n", 4);
}
