/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_four_five_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:20:43 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/19 16:21:44 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index_min(t_stack *a, int *index_min)
{
	int	min;
	int	index;

	index = 0;
	min = INT_MAX;
	while (a)
	{
		if (a->content < min)
		{
			min = a->content;
			*index_min = index;
		}
		index++;
		a = a->next;
	}
	return (min);
}

void	ft_find_index_second_min(t_stack *a, int min1, int *index_min)
{
	int	min2;
	int	index;

	index = 0;
	min2 = INT_MAX;
	while (a)
	{
		if (a->content < min2 && a->content > min1)
		{
			min2 = a->content;
			*index_min = index;
		}
		index++;
		a = a->next;
	}
}

void	ft_mouve_min(t_stack **a, t_stack **b, int min_i)
{
	int	size;

	size = ft_push_size(*a);
	if (min_i <= (size / 2))
		while (min_i-- > 0)
			ft_ra(a, 1);
	else
		while (min_i++ < size)
			ft_rra(a, 1);
	ft_pb(a, b, 1);
}
