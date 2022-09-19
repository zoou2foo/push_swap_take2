/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_n_deal_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:16:42 by vjean             #+#    #+#             */
/*   Updated: 2022/09/19 11:47:04 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	lst_last(t_stack *lst)
{
	t_stack	*first;

	first = lst;
	while (first->next != first)
	{
		if (first->next == NULL)
			return (*first);
	}
	return (*first);
}

void	add_lst(t_stack *lst, t_stack *ft_lstnew(void *content))
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*new;

	last = lst_last(lst);
	first->previous = new;
	last->next = new;
	new->next = first;
	new->previous = last;
}