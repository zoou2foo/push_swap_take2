/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bigger_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:20:37 by vjean             #+#    #+#             */
/*   Updated: 2022/10/13 15:54:18 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finding_all_pos(t_stack *stack_a, t_stack *stack_b)
{
	find_pos_a(stack_a);
	find_pos_b(stack_b);
}

int	finding_median(t_stack **stack_a)
{
	int	median;

	median = lstsize(*stack_a) / 2;
	return (median);
}

void	move_almost_all_in_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	cpt;
	int	i;
	int	median;

	i = 0;
	size = lstsize(*stack_a);
	cpt = 0;
	median = finding_median(stack_a);
	while (cpt < size && lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index < median)
			do_pb(stack_a, stack_b);
		else
			do_ra(stack_a, i);
		cpt++;
	}
}
// ^ problème avec plus de 6. Genre 7. Car à la fin, il reste que des index
// plus grand que la médiane, mais il reste plus que 3 chiffres
// il faut que j'ajuste mes conditions. Il faudrait regarder pour le
// plus petit index dans ce cas pour le pousser vers b

void	find_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*tmp;
	int		previous_index;

	head_a = *stack_a;
	head_b = *stack_b;
	previous_index = INT_MAX;
	while (*stack_b)
	{
		while (*stack_a)
		{
			if ((*stack_a)->index > (*stack_b)->index
				&& (*stack_a)->index < previous_index)
			{
					(*stack_b)->target_pos = (*stack_a)->pos_a;
					previous_index = (*stack_a)->index;
			}
			*stack_a = (*stack_a)->next;
		}
		*stack_a = head_a;
		if ((*stack_a)->index < (*stack_b)->index)
		{
			tmp = find_node_w_lower_index(*stack_a);
			(*stack_b)->target_pos = tmp->index;
		}
		*stack_b = (*stack_b)->next;
		*stack_a = head_a; //pour ensuite gérer ceux inférieur
	}
	*stack_b = head_b;
	find_cost(stack_a, stack_b);
}

void	do_algo_more_three(t_stack **stack_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((*stack_a)->index == find_bigger_index(*stack_a))
	{
		do_ra(stack_a, i);
		if ((*stack_a)->index > (*stack_a)->next->index)
			do_sa(stack_a);
	}
	else if ((*stack_a)->next->index == find_bigger_index(*stack_a))
	{
		do_rra(stack_a, j);
		if ((*stack_a)->index > (*stack_a)->next->index)
			do_sa(stack_a);
	}
	else if ((*stack_a)->index > (*stack_a)->next->index)
		do_sa(stack_a);
}
