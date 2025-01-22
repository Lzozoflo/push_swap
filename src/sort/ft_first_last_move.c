/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_last_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:16:02 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/22 14:05:49 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_first_move(t_stack **a, t_stack **b)
{
	t_data	*data;

	ft_pb(a, b, 1);
	ft_pb(a, b, 1);
	data = ft_smallest_count(a, b);
	ft_the_smallest(&data);
	ft_optimize_stack_rotation(a, b, &data);
	free(data);
}

void	ft_last_move(t_stack **a, t_stack **b)
{
	t_stack	*last;

	last = ft_push_last(*a);
	if (last->final_index > (*b)->final_index)
		ft_rra(a, 1);
	last = ft_push_last(*a);
	while (*b)
	{
		if (last->final_index > (*b)->final_index
			&& last->final_index < (*a)->final_index)
		{
			ft_rra(a, 1);
			last = ft_push_last(*a);
		}
		else
		{
			ft_pa(a, b, 1);
		}
	}
	while (last->final_index < (*a)->final_index)
	{
		ft_rra(a, 1);
		last = ft_push_last(*a);
	}
}
