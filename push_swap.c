/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:33:06 by vjean             #+#    #+#             */
/*   Updated: 2022/09/21 14:54:36 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a = ft_calloc(sizeof(t_stack), 1);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		is_alpha(av);
		check_numbers(av);
		print_split(av); //don't need it but just to see
		fill_lst(av, stack_a);
		check_doubles(stack_a);
	}
	if (ac > 2)
	{
		av++;
		is_alpha(av);
		check_numbers(av);
		print_split(av); //don't need it. just to see
		fill_lst(av, stack_a);
		check_doubles(stack_a);
	}
	t_stack *head;
	head = stack_a;
	while (stack_a)
	{
		printf("valeur de stack_a: %i\n", stack_a->value);
		stack_a = stack_a->next;
	}
	stack_a = head;
	free_node (stack_a); //free_node
	return (0);
}
// Thurs: check if sorted (function). Then, create index (int index in struct)
// code functions pa, pb, rra, ra, etc...
//t_stack *stack_b PAS OBLIGÉ de malloc