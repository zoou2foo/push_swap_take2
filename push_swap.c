/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:33:06 by vjean             #+#    #+#             */
/*   Updated: 2022/09/29 13:56:24 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = ft_calloc(sizeof(t_stack), 1);
	stack_b = NULL;
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		check_input(av, &stack_a);
		printf("---------------\n");
		do_rra(&stack_a);
		printf("---------------\n");
	}
	if (ac > 2)
	{
		av++;
		check_input(av, &stack_a);
		do_ss(&stack_a, &stack_a);
		do_ra(&stack_a);
	}
	free_node (stack_a); //free_node
	return (0);
}

void	print_lst(t_stack **stack_a)
{
	while (stack_a)
	{
		printf("stack_a->value = %d | stack_a->index = %d\n", (*stack_a)->value, (*stack_a)->index);
		*stack_a = (*stack_a)->next;
	}
}
//do_pb(&stack_a, &stack_b);
//do_sa(&stack_a);
//do_ss(&stack_a, &stack_a);
//do_ra(&stack_a);
//do_pb(&stack_a, &stack_b);
//do_pa(&stack_a, &stack_b);
//do_sa(&stack_a);
//do_rb(&stack_b);
//mettre des printf pour tester ss et ra.
// do_ss/do_rr/do_rrr: il faut que j'instaure un principe pour qu'il écrit
//qu'il a fait ss, rr ou rrr et non pas, sa sb/ ra rb / rra rrb. D'où l'utilité
//d'un int i pour true/false (0 1) dans les mouvements en questions
//t_stack *stack_b PAS OBLIGÉ de malloc

/*t_stack *head;
head = stack_a;
while (stack_a)
{
	printf("valeur de stack_a: %i | stack_a->index = %i\n", stack_a->value, stack_a->index);
	stack_a = stack_a->next;
}
stack_a = head;*/