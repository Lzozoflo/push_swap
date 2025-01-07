/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:43:36 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/07 14:01:10 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_head_higher_min(t_stack node_a, t_stack *b, t_data *data)
{
	while (b)
	{
		printf("bla");
		if (b->final_index < node_a.final_index)
			if (b->final_index >= data->final_index_b)
			{
				data->count = node_a.head_index + b->head_index;
				data->final_index_a = node_a.final_index;
				data->final_index_b = b->final_index;
			}
		b = b->next;
	}
}
				// if (data->count > node_a.head_index + b->head_index)

t_data	*ft_smallest_count(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_data	*head;
	t_data	*new;

	ft_pb(a, b, 0);
	ft_pb(a, b, 0);
	ft_rb(b, 0);
	ft_pb(a, b, 0);
	ft_pb(a, b, 0);
	tmp_a = *a;
	ft_add_utils(*a, *b);
	while (tmp_a)
	{
		new = ft_data_new();
		ft_find_head_higher_min(*tmp_a, *b, new);
		ft_data_add_back(&head, new);
		tmp_a = tmp_a->next;
	}
	return (new);
}

void	ft_data_count(t_stack **a, t_stack **b)
{
	t_data *head;

	head = ft_smallest_count(a, b);
	ft_print_data(head);
}


// void	ft_idk(void)
// {

// }
