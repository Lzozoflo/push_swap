/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turc_sort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:32:48 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/15 12:08:59 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_equal_or_not(t_stack **a, t_stack **b, t_data **data)
{
	if ((*a)->final_index == (*data)->node_a->final_index)
		return (0);
	if ((*b)->final_index == (*data)->node_b->final_index)
		return (0);
	return (1);
}

void	ft_r_or_rr_a(t_stack **a, t_stack **b, t_data **data, int the_way)
{
	if ((*data)->node_a->top_bot == 0)
	{
		if (the_way == 1)
			ft_while_ra(a, data);
		else
			ft_while_rra(a, data);
	}
	else if ((*data)->node_a->top_bot == 1)
		ft_while_ra(a, data);
	else if ((*data)->node_a->top_bot == -1)
		ft_while_rra(a, data);
}

void	ft_r_or_rr_b(t_stack **a, t_stack **b, t_data **data, int the_way)
{
	if ((*data)->node_b->top_bot == 0)
	{
		if (the_way == 1)
			ft_while_rb(b, data);
		else
			ft_while_rrb(b, data);
	}
	else if ((*data)->node_b->top_bot == 1)
		ft_while_rb(b, data);
	else if ((*data)->node_b->top_bot == -1)
		ft_while_rrb(b, data);
}

void	ft_who_move(t_stack **a, t_stack **b, t_data **data, int the_way)
{
	if ((*a)->final_index != (*data)->node_a->final_index)
		ft_r_or_rr_a(a, b, data, the_way);
	if ((*b)->final_index != (*data)->node_b->final_index)
		ft_r_or_rr_b(a, b, data, the_way);
}

t_stack	*ft_find_smaller(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*smaller;
	int		i;

	smaller = NULL;
	tmp = *b;
	i = INT_MAX;
	while (tmp)
	{
		if (tmp->final_index < i)
		{
			i = tmp->final_index;
			smaller = tmp;
		}
		tmp = tmp->next;
	}
	return (smaller);
}
