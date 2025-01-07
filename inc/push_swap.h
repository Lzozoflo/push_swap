/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:03:28 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/07 09:32:22 by fcretin          ###   ########.fr       */
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
	int				final_index;
	int				head_index;
	struct s_stack	*next;
}					t_stack;
typedef struct s_data
{
	int				final_index_a;
	int				final_index_b;
	int				count;
	struct s_data	*next;
}					t_data;

//trash fonction
void	test_to_print_lst(t_stack	**head_a, t_stack **head_b);
void	ft_print_two_stack(t_stack *a, t_stack *b);
void	ft_print_data(t_data *data);

void	ft_data_count(t_stack **a, t_stack **b);


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
// void	ft_push_add_back(t_stack **lst, t_stack *new);
void	ft_add_head_index(t_stack *lst);
void	ft_add_final_index(t_stack *lst);
void	ft_add_utils(t_stack *a, t_stack *b);
t_data	*ft_data_new(void);
void	ft_data_add_back(t_data **lst, t_data *new);
void	ft_push_add_front(t_stack **lst, t_stack *new);
t_stack	*ft_push_new(char *str);
t_stack	*ft_push_last(t_stack *lst);
void	ft_push_clear(t_stack **lst, void (*del)(int));
int		ft_push_size(t_stack *lst);
float	ft_push_size_fl(t_stack *lst);

// sort Directorie
int		ft_find_index_min(t_stack *a, int *index_min);
void	ft_find_index_second_min(t_stack *a, int min1, int *index_min);
void	ft_mouve_min(t_stack **a, t_stack **b, int min_i);
void	ft_little_sort(t_stack **a, t_stack **b, int len);


#endif
