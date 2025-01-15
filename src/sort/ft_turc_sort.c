/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turc_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:57:55 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/15 12:13:46 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small_head_index(t_stack *smaller, t_stack *max, t_stack **b)
{
	while ((smaller->top_bot == 1 || smaller->top_bot == 0)
		&& (*b)->final_index != max->final_index)
	{
		ft_rb(b, 1);
	}
	while (smaller->top_bot == -1 && (*b)->final_index != max->final_index)
	{
		ft_rrb(b, 1);
	}
}

void	ft_max_head_index(t_stack *smaller, t_stack *max, t_stack **b)
{
	while ((max->top_bot == 1 || max->top_bot == 0)
		&& (*b)->final_index != max->final_index)
	{
		ft_rb(b, 1);
	}
	while (max->top_bot == -1 && (*b)->final_index != max->final_index)
	{
		ft_rrb(b, 1);
	}
}

void	ft_max_on_top(t_stack **b)
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
		ft_max_head_index(smaller, max, b);
	}
}

void	ft_optimize_stack_rotation(t_stack **a, t_stack **b, t_data **data)
{
	int	top_bottom;

	top_bottom = 0;
	if ((*data)->node_a->top_bot == (*data)->node_b->top_bot)
	{
		if ((*data)->node_a->top_bot == 1 || (*data)->node_a->top_bot == 0)
			top_bottom = ft_while_rr(a, b, data);
		else
			top_bottom = ft_while_rrr(a, b, data);
	}
	else if ((*data)->node_a->top_bot == 0 || (*data)->node_b->top_bot == 0)
	{
		if ((*data)->node_a->top_bot == 1 || (*data)->node_b->top_bot == 1)
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
		if (size_a == 4)
			break ;
	}
	ft_little_sort(a, b, size_a - 1);
	ft_add_utils(*a, *b);
	ft_max_on_top(b);
}
