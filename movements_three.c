/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:41:49 by vjean             #+#    #+#             */
/*   Updated: 2022/09/28 14:22:53 by vjean            ###   ########.fr       */
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

}
//stack_a devient stack_a->next. Puis, le dernier devient le premier.