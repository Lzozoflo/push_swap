/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turc_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:57:55 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/09 09:56:06 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_the_smallest(t_data **data)
{
	t_data	*the_best;
	t_data	*tmp;

	the_best = *data;
	tmp = *data;
	tmp = tmp->next;
	while (tmp)
	{
		if (the_best->count > tmp->count)
			the_best = tmp;
		tmp = tmp->next;
	}
	tmp = *data;
	while (*data)
	{
		if ((*data) == the_best)
			data = (*data)->next;
		else
		{
			tmp = *data;
			data = (*data)->next;
			free(tmp);
		}
	}
}

void	ft_first_mouve(t_stack **a, t_stack **b)
{
	t_data	*head;

	ft_pb(a, b, 0);
	ft_pb(a, b, 0);
	// ft_pb(a, b, 0);
	// ft_pb(a, b, 0);
	// ft_pb(a, b, 0);
	// ft_pb(a, b, 0);
	head = ft_smallest_count(a, b);
	ft_the_smallest(&head);
	ft_bcl_p_data(head);
}

// void	ft_idk(void)
// {

// }

// void	ft_idk(void)
// {

// }
