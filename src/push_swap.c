/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:16:10 by jsebasti          #+#    #+#             */
/*   Updated: 2023/01/27 15:37:17 by jsebasti         ###   ########.fr       */
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
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		ft_error(0);
	valid_param(argc, argv);
	init_stack_a(&a, argc, argv);
	init_stack_b(&b);
	indexer(&a);
	check(&a, &b);
	ft_stackclear(&a);
	ft_stackclear(&b);
	return (0);
}
