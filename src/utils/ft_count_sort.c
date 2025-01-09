/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:43:36 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/09 17:57:37 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_find_head_higher_min(t_stack *node_a, t_stack *b, t_data *data)
{
	while (b)
	{
		if (b->final_index < node_a->final_index)
		{
			// if (b->final_index >= data->node_b->final_index)
			// {
			// 	data->count = node_a->head_index + b->head_index;
			// 	data->node_a = node_a;
			// 	data->node_b = b;
			// }
		}
		b = b->next;
	}
}

static void	ft_one_to_max(t_stack *node_a, t_stack *b, t_data *data)
{
	t_stack	*tmp;

	tmp = b;
	b = b->next;
	while (b)
	{
		if (tmp->final_index < b->final_index)
			tmp = b;
		b = b->next;
	}
	data->count = node_a->head_index + tmp->head_index;
	data->node_a = node_a;
	data->node_b = tmp;
}

t_data	*ft_smallest_count(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_data	*head;
	t_data	*new;

	head = NULL;
	tmp_a = *a;
	ft_add_utils(*a, *b);
	while (tmp_a)
	{
		new = ft_data_new();
		if (tmp_a->final_index != 1)
			ft_find_head_higher_min(tmp_a, *b, new);
		else
			ft_one_to_max(tmp_a, *b, new);
		ft_data_add_back(&head, new);
		tmp_a = tmp_a->next;
	}
	return (head);
}
