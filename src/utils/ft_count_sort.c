/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:43:36 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/15 12:12:19 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_find_head_higher_min(t_stack *node_a, t_stack *b, t_data *data)
{
	while (b)
	{
		if (b->final_index < node_a->final_index)
		{
			if (data->node_a == NULL)
			{
				data->count = node_a->head_index + b->head_index;
				data->node_a = node_a;
				data->node_b = b;
			}
			else if (b->final_index >= data->node_b->final_index)
			{
				data->count = node_a->head_index + b->head_index;
				data->node_a = node_a;
				data->node_b = b;
			}
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
	int		min_b;

	head = NULL;
	tmp_a = *a;
	min_b = ft_min(*b);
	ft_add_utils(*a, *b);
	while (tmp_a)
	{
		new = ft_data_new();
		if (!new)
			exit(ft_free_all(a, b, &head));
		if (tmp_a->final_index > min_b)
			ft_find_head_higher_min(tmp_a, *b, new);
		else
			ft_one_to_max(tmp_a, *b, new);
		ft_data_add_back(&head, new);
		tmp_a = tmp_a->next;
	}
	return (head);
}

int	ft_the_smallest(t_data **data)
{
	t_data	*the_smallest;
	t_data	*tmp;
	int		i;

	i = 1;
	the_smallest = *data;
	tmp = (*data)->next;
	while (tmp)
	{
		if (tmp->count < the_smallest->count)
			the_smallest = tmp;
		tmp = tmp->next;
		i++;
	}
	ft_free_except_smallest(data, the_smallest);
	*data = the_smallest;
	return (i);
}
