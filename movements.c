/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:54:36 by vjean             #+#    #+#             */
/*   Updated: 2022/09/23 11:28:55 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pb(t_stack *stack_a)
{
	t_stack	**stack_b;
	t_stack	*head_a;

	stack_b = NULL;
	head_a = *stack_a;
	*stack_a = (*stack_a)->next;
	head_a->next = *stack_b;
	*stack_b = head_a;
	printf("valeur à la head_a: %d\n", head_a->value);
	printf("valeur à la stack_a: %d\n", (*stack_a)->value);
	printf("valeur à la stack_b: %d\n", (*stack_b)->value);
}
