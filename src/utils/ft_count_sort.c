/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:43:36 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/08 19:09:01 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_find_head_higher_min(t_stack node_a, t_stack *b, t_data *data)
{
	while (b)
	{
		if (b->final_index < node_a.final_index)
		{
			if (b->final_index >= data->final_index_b)
			{
				data->count = node_a.head_index + b->head_index;
				data->final_index_a = node_a.final_index;
				data->final_index_b = b->final_index;
			}
		}
		b = b->next;
	}
}

static void	ft_one_to_max(t_stack node_a, t_stack *b, t_data *data)
{
	t_stack tmp;

	tmp = *b;
	b = b->next;
	while (b)
	{
		if (tmp.final_index < b->final_index)
			tmp = *b;
		b = b->next;
	}
	data->count = node_a.head_index + tmp.head_index;
	data->final_index_a = node_a.final_index;
	data->final_index_b = tmp.final_index;
}

t_data	*ft_smallest_count(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_data	*head;
	t_data	*new;

	head = NULL;
	ft_pb(a, b, 0);
	ft_pb(a, b, 0);
	ft_pb(a, b, 0);
	// ft_pb(a, b, 0);
	// ft_pb(a, b, 0);
	// ft_pb(a, b, 0);
	tmp_a = *a;
	ft_add_utils(*a, *b);
	while (tmp_a)
	{
		new = ft_data_new();
		if (tmp_a->final_index != 1)
			ft_find_head_higher_min(*tmp_a, *b, new);
		else
			ft_one_to_max(*tmp_a, *b, new);
		ft_data_add_back(&head, new);
		tmp_a = tmp_a->next;
	}
	// ft_print_data(*new);
	return (head);
}

void	ft_data_count(t_stack **a, t_stack **b)
{
	t_data	*head;

	head = ft_smallest_count(a, b);
	// ft_bcl_p_data(head);
}


