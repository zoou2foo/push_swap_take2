/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:33:06 by vjean             #+#    #+#             */
/*   Updated: 2022/09/19 08:58:06 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		print_split(av); //don't need it but just to see
		is_alpha(av);
		check_numbers(av);
	}
	if (ac > 2)
	{
		av++;
		print_split(av); //don't need it. just to see
		is_alpha(av);
		check_numbers(av);
	}
	return (0);
}