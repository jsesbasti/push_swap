/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:17:45 by jsebasti          #+#    #+#             */
/*   Updated: 2023/01/25 08:12:21 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackclear(t_stack *stack)
{
	t_elems	*tmp;

	if (!stack)
		return ;
	while (stack->first)
	{
		tmp = stack->first->next;
		free(stack->first);
		stack->first = tmp;
	}
	stack = NULL;
}

void	ft_cleanstacks(t_stack *a, t_stack *b)
{
	if (a != NULL)
		ft_stackclear(a);
	if (b != NULL)
		ft_stackclear(b);
	ft_error(3);
}

void
	ft_error(int num)
{
	if (num == 0)
		ft_printf("Error\n");
	else if (num == 1)
		ft_printf("Invalid Input\n");
	else if (num == 2)
		ft_printf("No node created\n");
	else if (num == 3)
		ft_printf("Movment error\n");
	exit(EXIT_FAILURE);
}
