/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_n_deal_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:16:42 by vjean             #+#    #+#             */
/*   Updated: 2022/09/20 11:41:58 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_lst(t_stack *stack_a)
{
	int		i;
	t_stack	*head_a;
	int		*tmp;

	i = 0;
	head_a = stack_a;
	tmp = stack_a->temp;
	if (check_doubles(tmp))
		return ;
	while (tmp[i])
	{
		stack_a->value = tmp[i];
		stack_a = stack_a->next;
		stack_a = malloc(sizeof(t_stack));
		i++;
	}
	stack_a->next = head_a;
}
//^peut-être node de trop de malloc
