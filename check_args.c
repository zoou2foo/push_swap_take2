/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:52:29 by vjean             #+#    #+#             */
/*   Updated: 2022/09/19 13:50:58 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//to check if there are letters in the args
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
void	check_numbers(char **av, t_info *info)
{
	int		i;
	int		temp;

	i = 0;
	info->head_a = NULL;
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
		else
		{
			temp = ft_atoi(av[i]);
			add_lst(info->head_a, lst_new(temp));
		}
		i++;
	}
}
//takes pointeur sur le premier, et fonction lstnew de temp ^

//void	check_doublons()
//don't forget to get rid of this function. Just for me at this point
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
