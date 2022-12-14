/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriejean <valeriejean@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:33:06 by vjean             #+#    #+#             */
/*   Updated: 2022/10/12 17:10:51 by valeriejean      ###   ########.fr       */
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
		check_how_many(&stack_a, &stack_b);
		print_stack(&stack_a, &stack_b);
	}
	if (ac > 2)
	{
		av++;
		check_input(av, &stack_a);
		check_how_many(&stack_a, &stack_b);
	}
	//free_node (stack_a); //free_node BESOIN de décommenter à la fin
	return (0);
}

void	print_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;
	t_stack *head_b;

	head = *stack_a;
	head_b = *stack_b;
	while (*stack_a != NULL)
	{
		printf("stack_a->value = %d | stack_a->pos_a = %d | stack_a->cost_a = %d\n", (*stack_a)->value, (*stack_a)->pos_a, (*stack_a)->cost_a);
		*stack_a = (*stack_a)->next;
	}
	while (*stack_b != NULL)
	{
		printf("stack_b->value = %d | stack_b->pos_b = %d | stack_b->target_pos = %d | stack_b->cost_b = %d\n", (*stack_b)->value, (*stack_b)->pos_b, (*stack_b)->target_pos, (*stack_b)->cost_b);
		*stack_b = (*stack_b)->next;
	}
	*stack_a = head;
	*stack_b = head_b;
}

// do_ss/do_rr/do_rrr: il faut que j'instaure un principe pour qu'il écrit
//qu'il a fait ss, rr ou rrr et non pas, sa sb/ ra rb / rra rrb. D'où l'utilité
//d'un int i pour true/false (0 1) dans les mouvements en questions
// même faire un int 1, 2, 3: 1 pour sa, 2 pour sb, 3 pour ss (par exemple)
//t_stack *stack_b PAS OBLIGÉ de malloc