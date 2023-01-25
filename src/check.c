/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:04:09 by jsebasti          #+#    #+#             */
/*   Updated: 2022/12/01 19:53:52 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "moves.h"

int	is_digit(int argc, char **argv)
{
	int	i;
	int	temp1;

	i = 0;
	while (++i < argc)
	{
		if (!ft_isdigit((int)argv[i]))
			return (ERRCODE0);
		temp1 = ft_atoi(argv[i]);
		if (!ft_check_maxint(temp1))
			return (ERRCODE0);
	}
	return (ERRCODE1);
}

int	duplicated(int argc, char **argv)
{
	int	i;
	int	j;
	int	temp1;
	int	temp2;

	i = 0;
	while (++i < argc)
	{
		j = i;
		temp1 = ft_atoi(argv[i]);
		while (++j < argc)
		{
			temp2 = ft_atoi(argv[j]);
			if (temp1 == temp2)
				return (ERRCODE0);
		}
	}
	return (ERRCODE1);
}

int	check_order(int argc, char **argv)
{
	int	i;
	int	temp1;
	int	temp2;

	i = 0;
	while (++i < argc)
	{
		temp1 = ft_atoi(argv[i]);
		temp2 = ft_atoi(argv[i + 1]);
		if (temp1 > temp2)
			return (ERRCODE0);
	}
	return (ERRCODE1);
}

void	valid_param(int argc, char **argv)
{
	if (!is_digit(argc, argv))
		ft_error(ERRCODE0);
	if (!duplicated(argc, argv))
		ft_error(ERRCODE0);
	if (check_order(argc, argv))
		exit(ERRCODE1);
}
