/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:33:06 by vjean             #+#    #+#             */
/*   Updated: 2022/10/03 13:02:55 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_calloc(sizeof(t_stack), 1);
	stack_b = NULL;
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		check_input(av, &stack_a);
		printf("1--------------\n");
		check_how_many(&stack_a);
		print_stack(&stack_a);
		printf("2--------------\n");
	}
	if (ac > 2)
	{
		av++;
		check_input(av, &stack_a);
	}
	//free_node (stack_a); //free_node BESOIN de décommenter à la fin
	return (0);
}

void	print_stack(t_stack **stack_a)
{
	while (*stack_a != NULL)
	{
		printf("stack_a->value = %d | stack_a->pos_a = %d\n", (*stack_a)->value, (*stack_a)->pos_a);
		*stack_a = (*stack_a)->next;
	}
}

void	print_lst(t_stack **stack_a)
{
	while (*stack_a != NULL)
	{
		printf("stack_a->value = %d | stack_a->index = %d | stack_a->pos_a = %d\n", (*stack_a)->value, (*stack_a)->index, (*stack_a)->pos_a);
		*stack_a = (*stack_a)->next;
	}
}

void	print_lst_b(t_stack **stack_b)
{
	while (*stack_b != NULL)
	{
		printf("stack_b->value = %d | stack_b->index = %d | stack_b->pos_b = %d\n", (*stack_b)->value, (*stack_b)->index, (*stack_b)->pos_b);
		*stack_b = (*stack_b)->next;
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
//do_rrb(&stack_b);
//print_lst_b(&stack_b);
//do_rra(&stack_a);
//		find_pos_a(stack_a);

// do_ss/do_rr/do_rrr: il faut que j'instaure un principe pour qu'il écrit
//qu'il a fait ss, rr ou rrr et non pas, sa sb/ ra rb / rra rrb. D'où l'utilité
//d'un int i pour true/false (0 1) dans les mouvements en questions
// même faire un int 1, 2, 3: 1 pour sa, 2 pour sb, 3 pour ss (par exemple)
//t_stack *stack_b PAS OBLIGÉ de malloc
