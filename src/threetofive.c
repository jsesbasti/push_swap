/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threetofive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:34:31 by jsebasti          #+#    #+#             */
/*   Updated: 2022/12/01 19:53:48 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "moves.h"

void	three_algor(t_stack *a)
{
	if (!ft_issorted(a->first))
		return ;
	if (a->first->idx == 0)
	{
		ft_rra(a);
		ft_sa(a);
	}
	else if (a->first->idx == 1 && a->first->next->idx == 0)
		ft_sa(a);
	else if (a->first->idx == 1 && a->first->next->idx == 2)
		ft_rra(a);
	if (a->first->idx == 2 && a->first->next->idx == 1)
	{
		ft_ra(a);
		ft_sa(a);
	}
	else if (a->first->idx == 2 && a->first->next->idx == 0)
		ft_ra(a);
}

void	four_algor(t_stack *a, t_stack *b)
{
	ft_putfirst_a(a, 0);
	if (!ft_issorted(a->first))
		return ;
	ft_pb(a, b);
	indexer(a);
	three_algor(a);
	ft_pa(a, b);
}

void	five_algor(t_stack *a, t_stack *b)
{
	ft_putfirst_a(a, 0);
	if (!ft_issorted(a->first))
		return ;
	ft_pb(a, b);
	ft_putfirst_a(a, 1);
	ft_pb(a, b);
	three_algor(a);
	ft_pa(a, b);
	ft_pa(a, b);
}
