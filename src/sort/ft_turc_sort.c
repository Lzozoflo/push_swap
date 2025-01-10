/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turc_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:57:55 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/10 17:43:08 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_mouve(t_stack **a, t_stack **b)
{
	t_data	*data;

	ft_pb(a, b, 0);
	ft_pb(a, b, 0);
	data = ft_smallest_count(a, b);
	// ft_bcl_p_data(data);
	ft_the_smallest(&data);

	// ft_print_data(*data);
	ft_optimize_stack_rotation(a, b, data);
	// ft_pa(a, b, 0);
	// ft_pa(a, b, 0);
}

void	ft_optimize_stack_rotation(t_stack **a, t_stack **b, t_data **data)
{
	int	top_bottom;

	top_bottom = 0;
	if ((*data)->node_a->top_bot == (*data)->node_b->top_bot)
	{
		if ((*data)->node_a->top_bot == 1 || (*data)->node_a->top_bot == 0)
			top_bottom = ft_equal_top_to_bot(a, b, data);
		else
			top_bottom = ft_equal_bot_to_top(a, b, data);
	}
	else if ((*data)->node_a->top_bot == 0 || (*data)->node_b->top_bot == 0)
	{
		if ((*data)->node_a->top_bot == 1 || (*data)->node_b->top_bot == 1)
			top_bottom = ft_equal_top_to_bot(a, b, data);
		else
			top_bottom = ft_equal_bot_to_top(a, b, data);
	}
	if ((*a)->final_index == (*data)->node_a->final_index
		&& (*b)->final_index == (*data)->node_b->final_index)
		return (ft_pb(a, b, 1));
	ft_who_move(a, b, data, top_bottom);
	ft_pb(a, b, 1);
}


// void	ft_idk(void)
// {

// }

// void	ft_idk(void)
// {

// }

// void	ft_idk(void)
// {

// }
