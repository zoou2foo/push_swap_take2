/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:41:49 by vjean             #+#    #+#             */
/*   Updated: 2022/10/04 08:41:19 by vjean            ###   ########.fr       */
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
	int		i;

	i = 1;
	old_head = *stack_a; // old_head = 4 3 2 1; comme stack_a pour le moment
	size = lstsize(old_head); // size devient 4
	if (size == 1)
		return ;
	last = lstlast(old_head); // last devient 1
	new_head = last; // maintenant, new_head pointe 1; pour être au début
	last->next = old_head; //le node suivant 1 devient old_head qui pointe 4
	while (i < size) //tant que i est plus petit que 4 (le size de la lst)
	{
		last = last->next; // 1->4; 4->3; 3->2; 2->1;
		i++;
	}
	last->next = NULL; // skip mais fonctionne...
	*stack_a = new_head;
	//print_lst(stack_a);
}
// ^ besoin de plusieurs nouvelles variables
// ^ last pour trouver le dernier node de la liste. Old_head qui représente
// ^ l'ancien pointeur/début de la liste. Puis, new_head représente le nouveau
// ^ pointeur/début de la liste avec le dernier node qui est en premier.
// ^ Un int pour déterminer la longueur de la liste pour être en mesure d'aller
// ^ récupérer le nouveau "dernier" node. Puis, un index pour parcourir la list
// ^ selon la size.

void	do_rrb(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*old_head;
	t_stack	*new_head;
	int		size;
	int		i;

	printf("let's do this fucking shit rrb\n");
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
	print_lst_b(stack_b);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	do_rra(stack_a);
	do_rrb(stack_b);
}