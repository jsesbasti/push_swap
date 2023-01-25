/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:47:20 by jsebasti          #+#    #+#             */
/*   Updated: 2023/01/25 05:38:51 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "moves.h"

void	ft_stack_swap(t_stack *stack)
{
	t_elems	*tmp;
	int		tmpnbr;

	tmp = stack->first->next;
	if (stack->len == 2)
	{
		tmpnbr = stack->first->val;
		stack->first->val = stack->first->next->val;
		stack->first->next->val = tmpnbr;
	}
	else if (stack->len > 2)
	{
		stack->first->next->next->back = stack->first;
		stack->first->next = stack->first->next->next;
		tmp->next = stack->first;
		tmp->back = NULL;
		stack->first->back = tmp;
		stack->first = tmp;
	}
}

void	ft_sa(t_stack *a)
{
	ft_stack_swap(a);
	if (ft_printf("%s", INS_SA) == ERR_NUM)
		ft_cleanstacks(a, NULL);
}

void	ft_sb(t_stack *b)
{
	t_elems	*aux;

	aux = b->first;
	b->first = b->first->next;
	b->first->next = aux;
	if (ft_printf("%s", INS_SB) == ERR_NUM)
		ft_cleanstacks(b, NULL);
}


void	ft_ss(t_stack *a, t_stack *b)
{
	if (a->len > 1 && b->len > 1)
	{
		ft_stack_swap(a);
		ft_stack_swap(b);
		if (ft_printf("%s", INS_SS) == ERR_NUM)
			ft_cleanstacks(a, b);
	}
}
