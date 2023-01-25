/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:19:45 by jsebasti          #+#    #+#             */
/*   Updated: 2023/01/25 05:31:27 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

// Instructions
# define INS_PA		(char *)"pa\n"
# define INS_PB		(char *)"pb\n"
# define INS_SA		(char *)"sa\n"
# define INS_SB		(char *)"sb\n"
# define INS_SS		(char *)"ss\n"
# define INS_RA		(char *)"ra\n"
# define INS_RB		(char *)"rb\n"
# define INS_RR		(char *)"rr\n"
# define INS_RRA	(char *)"rra\n"
# define INS_RRB	(char *)"rrb\n"
# define INS_RRR	(char *)"rrr\n"

// Directions for stack
# define ROTATE		(int)1
# define RROTATE	(int)2
# define ONTOP		(int)3

# include "push_swap.h"

// Push Moves
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);

// Swap moves
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);

// Rotate moves
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);

// Reverese rotate moves
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);

// Sort Moves Utils
void	ft_putfirst_a(t_stack *a, int nbr);
void	ft_putfirst_b(int nbr, t_stack *a, t_stack *b);

#endif
