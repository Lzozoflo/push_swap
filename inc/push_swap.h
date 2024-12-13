/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:03:28 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/13 18:04:51 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	int				pos;
	char			*count;
	struct s_stack	*next;
}					t_stack;

// no dir
void	ft_isneg(t_stack **a, t_stack **b);

// utils Directorie
void	ft_push_lstadd_front(t_stack **lst, t_stack *new);
// void	ft_push_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_push_lstnew(long int content);
t_stack	*ft_push_lstlast(t_stack *lst);
void	ft_push_lstclear(t_stack **lst, void (*del)(int));
int		ft_push_lstsize(t_stack *lst);

// instructions Directorie
// swap
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);

// push
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);

// rotate
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);

// reverse rotate
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);

#endif
