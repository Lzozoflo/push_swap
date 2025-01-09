/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:43:36 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/09 09:55:52 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_except_smallest(t_data **data, t_data *the_best)
{
	t_data	*tmp;
	t_data	*prev;
	t_data	*next;

	tmp = data;
	prev = NULL;
	while (tmp)
	{
		next = tmp->next;
		if (tmp == the_best)
		{
			if (!prev)
				*data = tmp; // Mettre à jour la tête si nécessaire
			else
				prev->next = tmp; // Relier les nœuds correctement
		}
		else
			free(tmp);
		tmp = next;
	}
	the_best->next = NULL;
}

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
	t_stack	tmp;

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
	return (head);
}
