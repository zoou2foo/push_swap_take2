/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:33:06 by vjean             #+#    #+#             */
/*   Updated: 2022/09/20 14:57:04 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	array_size(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		i++;
	}
	return (i);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a = malloc(sizeof(t_stack));
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		is_alpha(av);
		check_numbers(av, stack_a, array_size(av));
		print_split(av); //don't need it but just to see
		fill_lst(stack_a);
	}
	if (ac > 2)
	{
		av++;
		is_alpha(av);
		check_numbers(av, stack_a, array_size(av));
		print_split(av); //don't need it. just to see
		fill_lst(stack_a);
	}
	return (0);
}
// Tomorrow (Wednesday):check if I take negative int. check if check_doubles
// work. Maybe start to look for leaks... From there, I can check Step Three
// in my plan, Notion.