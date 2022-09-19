/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_n_deal_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:16:42 by vjean             #+#    #+#             */
/*   Updated: 2022/09/19 14:43:41 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lst_last(t_info *info)
{
	t_stack	*first;

	first = info->head_a;
	while (first->next != first)
	{
		if (first->next == NULL)
			return (first);
	}
	return (first);
}

void	add_lst(t_info *info, t_stack *temp)
{
	t_stack	*last;

	last = lst_last(info->head_a);
	info->head_a->previous = temp;
	last->next = temp;
	temp->next = info->head_a;
	temp->previous = last;
	printf("node added: %d\n", temp->value);
}

t_stack	*lst_new(int temp)
{
	t_stack	*node;

	node = ft_calloc(1, sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = temp;
	node->next = NULL;
	return (node);
}