/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:43:49 by vjean             #+#    #+#             */
/*   Updated: 2022/10/12 14:27:24 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	plan_moves(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	int	i;

	i = 0;
	if (cost_a < 0 && cost_b < 0)
		setup_rrr(stack_a, stack_b, cost_a, cost_b);
	else if (cost_a > 0 && cost_b > 0)
		setup_rr(stack_a, stack_b, cost_a, cost_b);
	setup_ra(stack_a, cost_a);
	setup_rb(stack_b, cost_b);
	do_pa(stack_a, stack_b);
}
// ^ besoin de changer mes moves pour qu'il prenne un int et le int détermine
// le nombre de fois à faire le move. Puis, je dois ajouter write(1, "ra", 2);
// le move qu'il a fait.
//peut-être besoin de le garder plus vers la fin pour check

void	setup_rrr(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	int	i;

	while (cost_a < 0 && cost_b < 0)
	{
		i = 1;
		do_rrr(stack_a, stack_b, i);
		if (cost_a == 0 && cost_b < 0)
		{
			i = 0;
			do_rrb(stack_b, i);
		}
		else if (cost_a < 0 && cost_b == 0)
		{
			i = 0;
			do_rra(stack_a, i);
		}
		cost_a++;
		cost_b++;
	}
}

void	setup_rr(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	int	i;

	while (cost_a > 0 && cost_b > 0)
	{
		i = 1;
		do_rr(stack_a, stack_b, i);
		if (cost_a == 0 && cost_b > 0)
		{
			i = 0;
			do_rb(stack_b, i);
		}	
		else if (cost_a > 0 && cost_b == 0)
		{
			i = 0;
			do_ra(stack_a, i);
		}	
		cost_a--;
		cost_b--;
	}
}

void	setup_ra(t_stack **stack_a, int cost_a)
{
	int	i;

	if (cost_a > 0)
	{
		i = 0;
		do_ra(stack_a, i);
		cost_a--;
	}
}

void	setup_rb(t_stack **stack_b, int cost_b)
{
	int	i;

	if (cost_b > 0)
	{
		i = 0;
		do_rb(stack_b, i);
		cost_b--;
	}
}