/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:39:41 by jsebasti          #+#    #+#             */
/*   Updated: 2023/01/25 05:35:00 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"
#include "push_swap.h"

static void	ft_push_src(t_stack *src, t_elems *tmp)
{
	if (src->len > 1)
	{
		src->first = tmp->next;
		src->first->back = NULL;
	}
	else
	{
		src->first = NULL;
		src->last = NULL;
	}
}

static void	ft_push_dst(t_stack *dst, t_elems *tmp)
{
	if (dst->len < 1)
	{
		dst->first = tmp;
		dst->last = tmp;
		tmp->next = NULL;
		tmp->back = NULL;
	}
	else
	{
		tmp->next = dst->first;
		dst->first->back = tmp;
		dst->first = tmp;
	}
}

static void	ft_stack_push(t_stack *dst, t_stack *src)
{
	t_elems	*tmp;

	tmp = src->first;
	ft_push_src(src, tmp);
	ft_push_dst(dst, tmp);
	++dst->len;
	--src->len;
}

void	ft_pa(t_stack *a, t_stack *b)
{
	if (b->len == 0)
		return ;
	ft_stack_push(a, b);
	if (ft_printf("%s", INS_PA) == ERR_NUM)
		ft_cleanstacks(a, b);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	if (a->len == 0)
		return ;
	ft_stack_push(b, a);
	if (ft_printf("%s", INS_PB) == ERR_NUM)
		ft_cleanstacks(a, b);
}
