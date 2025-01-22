/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turc_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:57:55 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/22 16:13:17 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_small_head_index(t_stack *smaller, t_stack *max, t_stack **b)
{
	while ((smaller->pos == 1 || smaller->pos == 0)
		&& (*b)->final_index != max->final_index)
	{
		ft_rb(b, 1);
	}
	while (smaller->pos == -1 && (*b)->final_index != max->final_index)
	{
		ft_rrb(b, 1);
	}
}

static void	ft_max_head_index(t_stack *max, t_stack **b)
{
	while ((max->pos == 1 || max->pos == 0)
		&& (*b)->final_index != max->final_index)
	{
		ft_rb(b, 1);
	}
	while (max->pos == -1 && (*b)->final_index != max->final_index)
	{
		ft_rrb(b, 1);
	}
}

static void	ft_max_on_top(t_stack **b)
{
	t_stack	*smaller;
	t_stack	*max;

	smaller = ft_find_smaller(b);
	if (smaller->next == NULL)
		return ;
	max = smaller->next;
	if (smaller->head_index <= max->head_index)
	{
		ft_small_head_index(smaller, max, b);
	}
	else
	{
		ft_max_head_index(max, b);
	}
}

void	ft_optimize_stack_rotation(t_stack **a, t_stack **b, t_data **data)
{
	int	top_bottom;

	top_bottom = 0;
	if ((*data)->node_a->pos == (*data)->node_b->pos)
	{
		if ((*data)->node_a->pos == 1 || (*data)->node_a->pos == 0)
			top_bottom = ft_while_rr(a, b, data);
		else
			top_bottom = ft_while_rrr(a, b, data);
	}
	else if ((*data)->node_a->pos == 0 || (*data)->node_b->pos == 0)
	{
		if ((*data)->node_a->pos == 1 || (*data)->node_b->pos == 1)
			top_bottom = ft_while_rr(a, b, data);
		else
			top_bottom = ft_while_rrr(a, b, data);
	}
	if ((*a)->final_index == (*data)->node_a->final_index
		&& (*b)->final_index == (*data)->node_b->final_index)
		return (ft_pb(a, b, 1));
	ft_who_move(a, b, data, top_bottom);
	ft_pb(a, b, 1);
}

void	ft_sort_to_b(t_stack **a, t_stack **b)
{
	t_data	*data;
	int		size_a;

	while (1)
	{
		data = ft_smallest_count(a, b);
		size_a = ft_the_smallest(&data);
		ft_optimize_stack_rotation(a, b, &data);
		free(data);
		if (size_a == 7)
			break ;
	}
	ft_little_sort(a, b, size_a - 1);
	ft_add_utils(*a, *b);
	ft_max_on_top(b);
}
