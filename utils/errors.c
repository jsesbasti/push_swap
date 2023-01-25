/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:17:45 by jsebasti          #+#    #+#             */
/*   Updated: 2022/12/01 19:53:52 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_stackclear(t_stack *stack)
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

void
	ft_cleanstacks(t_stack *a, t_stack *b)
{
	if (a != NULL)
		ft_stackclear(a);
	if (b != NULL)
		ft_stackclear(b);
	ft_error(ERRCODE3);
}

void
	ft_error(int num)
{
	if (num == ERRCODE0)
		write(STDERR_FILENO, ERR_MSG0, ft_strlen(ERR_MSG0));
	else if (num == ERRCODE1)
		write(STDERR_FILENO, ERR_MSG1, ft_strlen(ERR_MSG1));
	else if (num == ERRCODE2)
		write(STDERR_FILENO, ERR_MSG2, ft_strlen(ERR_MSG2));
	else if (num == ERRCODE3)
		write(STDERR_FILENO, ERR_MSG3, ft_strlen(ERR_MSG3));
	exit(EXIT_FAILURE);
}
