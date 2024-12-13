/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:35:50 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/13 11:33:18 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (b && *b)
	{
		tmp = (*a);
		(*a) = (*b);
		*b = (*b)->next;
		(*b)->next = tmp;
	}
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (a && *a)
	{
		tmp = (*b);
		(*b) = (*a);
		*a = (*a)->next;
		(*a)->next = tmp;
	}
}
