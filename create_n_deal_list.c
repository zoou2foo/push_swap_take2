/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_n_deal_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:16:42 by vjean             #+#    #+#             */
/*   Updated: 2022/10/11 15:23:56 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_node(t_stack *stack_a)
{
	t_stack	*tempo;

	while (stack_a)
	{
		tempo = stack_a->next;
		free (stack_a);
		stack_a = tempo;
	}
}

void	fill_lst(char **av, t_stack *stack_a)
{
	int	i;

	i = 0;
	while (av[i])
	{
		stack_a->value = ft_atoi(av[i]);
		i++;
		if (av[i] != NULL)
		{
			stack_a->next = ft_calloc(sizeof(t_stack), 1);
			stack_a = stack_a->next;
		}
		else
			stack_a->next = NULL;
	}
}
// ^ stack_a->value = ft_atoi(av[i]); //met av[i] dans ma liste
// ^	i++; //on incrémente pour voir le prochain
// ^ stack_a = stack_a->next; //incrément de ta liste

int	check_if_sorted(t_stack *stack_a)
{
	t_stack	*head_a;

	head_a = stack_a;
	while (stack_a)
	{
		if (stack_a->next != NULL && stack_a->value > stack_a->next->value)
			return (1);
		stack_a = stack_a->next;
	}
	stack_a = head_a;
	return (0);
}
// ^ "stack_a = stack_a->next;" doit aller au prochain pour voir; sinon ne 
// rentre pas dans le if

void	setup_index(t_stack *stack_a)
{
	t_stack	*comp;
	t_stack	*start;

	comp = stack_a;
	start = stack_a;
	while (comp)
	{
		while (stack_a)
		{
			if (stack_a->value > comp->value)
			{
				stack_a->index++;
			}
			stack_a = stack_a->next;
		}
		stack_a = start;
		comp = comp->next;
	}
}
//index = 0. Un élément sera à 0.

int	lstsize(t_stack *stack_a)
{
	t_stack	*list;
	int		i;

	list = stack_a;
	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

//changed my lst_size. It used to be the following
	/*(*stack_a)->size_max = 1;
	if (!*stack_a)
		return (0);
	while ((*stack_a)->next != NULL)
	{
		(*stack_a)->size_max++;
		*stack_a = (*stack_a)->next;
	}
	return ((*stack_a)->size_max);*/
// ^I did create a variable in my struc to carry the list size
// not fully working for my rra movement.