/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:16:10 by jsebasti          #+#    #+#             */
/*   Updated: 2022/12/01 19:53:51 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "moves.h"

void	check(t_stack *a, t_stack *b)
{
	if (a->len == 2)
		ft_sa(a);
	else if (a->len == 3)
		three_algor(a);
	else if (a->len == 4)
		four_algor(a, b);
	else if (a->len == 5)
		five_algor(a, b);
	else if (a->len <= 20)
		ft_sort_bigger(a, b, 2);
	else if (a->len <= 150)
		ft_sort_bigger(a, b, 4);
	else
		ft_sort_bigger(a, b, 8);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 1)
		return (ERRCODE0);
	valid_param(argc, argv);
	init_stack_a(&a, argc, argv);
	init_stack_b(&b);
	indexer(&a);
	check(&a, &b);
	ft_stackclear(&a);
	ft_stackclear(&b);
	return (0);
}