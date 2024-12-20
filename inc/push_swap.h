/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:03:28 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/20 10:16:00 by fcretin          ###   ########.fr       */
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
	t_stack	**head_a;
	t_stack	**head_b;
	int		size_a;
	int		size_b;
	int		mv;
}				t_stack;

typedef struct s_stack
{
	struct s_stack	*prev;
	int				content;
	struct s_stack	*next;
}				t_stack;

//trash fonction
int	test_to_print_lst(t_stack	**head_a, t_stack **head_b);
void	ft_print_two_stack(t_stack *a, t_stack *b);

// swap instructions Directorie
void	ft_sa(t_stack **a, int print);
void	ft_sb(t_stack **b, int print);
void	ft_ss(t_stack **a, t_stack **b);
// push instructions Directorie
void	ft_pa(t_stack **a, t_stack **b, int print);
void	ft_pb(t_stack **a, t_stack **b, int print);
// rotate instructions Directorie
void	ft_ra(t_stack **a, int print);
void	ft_rb(t_stack **b, int print);
void	ft_rr(t_stack **a, t_stack **b);
// reverse rotate instructions Directorie
void	ft_rra(t_stack **a, int print);
void	ft_rrb(t_stack **b, int print);
void	ft_rrr(t_stack **a, t_stack **b);

// utils Directorie
void	ft_push_add_front(t_stack **lst, t_stack *new);
// void	ft_push_add_back(t_stack **lst, t_stack *new);
t_stack	*ft_push_new(char *str);
t_stack	*ft_push_last(t_stack *lst);
void	ft_push_clear(t_stack **lst, void (*del)(int));
int		ft_push_size(t_stack *lst);

// sort Directorie
int		ft_find_med(t_stack *stack, int target);
int		ft_find_median(t_stack *stack, int len);
void	ft_med_sort_a(t_stack **a, t_stack **b);

// void	ft_med_sort_b(t_stack **a, t_stack **b);

int		ft_find_index_min(t_stack *a, int *index_min);
void	ft_find_index_second_min(t_stack *a, int min1, int *index_min);
void	ft_mouve_min(t_stack **a, t_stack **b, int min_i);
void	ft_little_sort(t_stack **a, t_stack **b, int len);
void	ft_pre_sort(t_stack **a, t_stack **b);

#endif
