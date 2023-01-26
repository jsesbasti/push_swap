/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:33:20 by jsebasti          #+#    #+#             */
/*   Updated: 2023/01/26 10:28:14 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elems	*newnode(int nbr)
{
	t_elems	*new;

	new = (t_elems *)malloc(sizeof(t_elems));
	if (!new)
	{
		new = NULL;
		return (new);
	}
	new->val = nbr;
	new->idx = 0;
	new->next = NULL;
	new->back = NULL;
	return (new);
}

void	init_stack_a(t_stack *a, int argc, char **argv)
{
	t_elems	*lst;
	t_elems	*tmp;

	a->len = -1;
	a->first = NULL;
	a->last = NULL;
	lst = NULL;
	while (++a->len < argc - 1)
	{
		lst = newnode(ft_atoi(argv[a->len + 1]));
		ft_check_node(lst, a);
		if (!a->last)
		{
			a->first = lst;
			a->last = lst;
		}
		else
		{
			tmp = a->last;
			a->last = lst;
			tmp->next = a->last;
			a->last->back = tmp;
		}
	}
}

void	init_stack_b(t_stack *b)
{
	b->len = 0;
	b->first = NULL;
	b->last = NULL;
}

void	indexer(t_stack *stack)
{
	t_elems	*tmp;
	t_elems	*current;
	int		ind1;
	int		ind2;

	current = stack->first;
	ind2 = -1;
	while (++ind2 < stack->len)
	{
		ind1 = 0;
		tmp = stack->first;
		while (tmp)
		{
			if (tmp->val < current->val)
				ind1++;
			tmp = tmp->next;
		}
		current->idx = ind1;
		current = current->next;
	}
}
