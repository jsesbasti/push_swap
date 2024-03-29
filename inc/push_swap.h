/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:28:35 by jsebasti          #+#    #+#             */
/*   Updated: 2023/01/25 11:25:03 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libs/Libft/libft.h"
# include "../Libs/printf/ft_printf.h"
# include <limits.h>

typedef struct s_elems
{
	int				val;
	int				idx;
	struct s_elems	*next;
	struct s_elems	*back;
}					t_elems;

typedef struct s_stack
{
	int		len;
	t_elems	*first;
	t_elems	*last;
}			t_stack;

// Push Swap Utils
int		ft_issorted(t_elems *stack);
int		ft_check_maxint(int nbr);
int		ft_while_isdigit(char *str);
void	ft_check_node(t_elems *lst, t_stack *stack);
ssize_t	ft_check_first(t_elems *first, ssize_t pos, int nbr);

// Check Params
void	valid_param(int nbr, char **str);

// Stack initiation
t_elems	*newnode(int nbr);
void	init_stack_a(t_stack *a, int nbr, char **str);
void	init_stack_b(t_stack *b);
void	indexer(t_stack *stack);

// Tiny sorting
void	three_algor(t_stack *a);
void	four_algor(t_stack *a, t_stack *b);
void	five_algor(t_stack *a, t_stack *b);

// Chunk sorting
void	ft_sort_bigger(t_stack *a, t_stack *b, int chunks);

// Error Functions
void	ft_error(int num);
void	ft_stackclear(t_stack *stack);
void	ft_cleanstacks(t_stack *a, t_stack *b);

#endif
