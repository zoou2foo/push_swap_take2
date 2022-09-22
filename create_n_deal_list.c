/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_n_deal_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:16:42 by vjean             #+#    #+#             */
/*   Updated: 2022/09/22 13:59:35 by vjean            ###   ########.fr       */
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
		stack_a->value = ft_atoi(av[i]); //met av[i] dans ma liste
		i++; //on incrémente pour voir le prochain
		if (av[i] != NULL)
		{
			stack_a->next = ft_calloc(sizeof(t_stack), 1);
			stack_a = stack_a->next; //incrément de ta liste
		}
		else
			stack_a->next = NULL;
	}
}

void	check_if_sorted(t_stack *stack_a)
{
	while (stack_a->next != NULL && stack_a->value < stack_a->next->value)
	{
		stack_a = stack_a->next; //doit aller au prochain pour voir; sinon ne rentre pas dans le if
		if (stack_a->value > stack_a->next->value)
		{
			printf("pas trié\n"); //just for me
			break ;
		}
	}
}

void	setup_index(t_stack *stack_a)
{
	t_stack	*comp;
	t_stack *start;

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

/*int	lstsize(t_stack *stack_a)
{
	stack_a->size_max = 1;
	if (!stack_a)
		return (0);
	while (stack_a->next != NULL)
	{
		stack_a->size_max++;
		stack_a = stack_a->next;
	}
	return (stack_a->size_max);
}*/
