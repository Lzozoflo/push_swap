/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turc_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:57:55 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/09 17:53:42 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_the_smallest(t_data **data)
{
	t_data	*the_smallest;
	t_data	*tmp;

	the_smallest = *data;
	tmp = (*data)->next;
	while (tmp)
	{
		if (tmp->count < the_smallest->count)
			the_smallest = tmp;
		tmp = tmp->next;
	}
	ft_free_except_smallest(data, the_smallest);
	*data = the_smallest;
}

void	ft_first_mouve(t_stack **a, t_stack **b)
{
	t_data	*data;

	ft_pb(a, b, 0);
	ft_pb(a, b, 0);
	data = ft_smallest_count(a, b);
	// ft_the_smallest(&data);

	// ft_print_data(*head);
	// ft_pa(a, b, 0);
	// ft_pa(a, b, 0);
}

void	ft_idk(t_stack **a, t_stack **b, t_data **data)
{


}

// void	ft_idk(void)
// {

// }
