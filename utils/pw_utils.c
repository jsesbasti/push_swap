/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:16:28 by jsebasti          #+#    #+#             */
/*   Updated: 2022/12/01 19:53:50 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "moves.h"

int
	ft_issorted(t_elems *lst)
{
	while (lst->next)
	{
		if (lst->val > lst->next->val)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int
	ft_check_maxint(int nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}

int
	ft_while_isdigit(char *str)
{
	if ((str[1] && str[0] == '-')
		|| (str[1] && str[0] == '+'))
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void
	ft_check_node(t_elems *lst, t_stack *stack)
{
	if (!lst)
		ft_stackclear(stack);
}

ssize_t
	ft_check_first(t_elems *first, ssize_t pos, int nbr)
{
	while (first)
	{
		if (first->idx == nbr)
			break ;
		++pos;
		first = first->next;
	}
	return (pos);
}
