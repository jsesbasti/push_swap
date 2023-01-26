/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:42:57 by jsebasti          #+#    #+#             */
/*   Updated: 2023/01/25 06:33:36 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"
#include "push_swap.h"

static void	ft_rotate_stack(t_stack *stack)
{
	t_elems	*tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->first;
	stack->first = tmp->next;
	stack->first->back = NULL;
	tmp->next = NULL;
	tmp->back = stack->last;
	stack->last->next = tmp;
	stack->last = tmp;
}

void	ft_ra(t_stack *a)
{
	if (a->len > 1)
	{
		ft_rotate_stack(a);
		if (ft_printf("%s", INS_RA) == -1)
			ft_cleanstacks(a, NULL);
	}
}

void	ft_rb(t_stack *b)
{
	if (b->len > 1)
	{
		ft_rotate_stack(b);
		if (ft_printf("%s", INS_RB) == -1)
			ft_cleanstacks(NULL, b);
	}
}

void	ft_rr(t_stack *a, t_stack *b)
{
	if (a->len > 1 && b->len > 1)
	{
		ft_rotate_stack(a);
		ft_rotate_stack(b);
		if (ft_printf("%s", INS_RR) == -1)
			ft_cleanstacks(a, b);
	}
}
