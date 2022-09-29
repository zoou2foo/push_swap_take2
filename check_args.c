/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:52:29 by vjean             #+#    #+#             */
/*   Updated: 2022/09/29 13:25:16 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//to check if there are letters in the args. Je veux peut-être le faire avec chiffres
void	is_alpha(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] >= 'A' && av[i][j] <= 'Z')
				|| (av[i][j] >= 'a' && av[i][j] <= 'z'))
			{
				printf("letters"); //no need but to know I'm doing
				exit (0);
			}
			j++;
		}
		i++;
	}
}

//to check if there are only INT
void	check_numbers(char **av)
{
	int		i;

	i = 0;
	while (av[i])
	{
		if (ft_strlen(av[i]) >= 11)
		{
			printf("trop long; so not an int"); //no need. Just to know for me
			exit (0);
		}
		else if (ft_atol(av[i]) < INT_MIN || ft_atol(av[i]) > INT_MAX)
		{
			write(2, "Error\n", 6);
			exit (0);
		}
		i++;
	}
}

//to check if there are doubles
int	check_doubles(t_stack *stack_a)
{
	t_stack	*head_a;
	t_stack	*beginning;

	head_a = stack_a;
	beginning = stack_a;
	while (head_a)
	{
		while (stack_a)
		{
			if (stack_a->value == head_a->value && stack_a != head_a)
			{
				write(2, "Error\n", 7);
				return (1);
			}
			stack_a = stack_a->next;
		}
		stack_a = beginning;
		head_a = head_a->next;
	}
	return (0);
}

void	print_split(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		printf("av[%i]: %s\n", i, av[i]);
		i++;
	}
}
//^don't forget to get rid of this function. Just for me at this point^

void	check_input(char **av, t_stack **stack_a)
{
	is_alpha(av);
	check_numbers(av);
	print_split(av); //don't need it but just to see
	fill_lst(av, *stack_a);
	check_doubles(*stack_a);
	check_if_sorted(*stack_a);
	setup_index(*stack_a);
}