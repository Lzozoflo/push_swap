/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:28:29 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/13 11:34:00 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a)
{
	t_stack	*tmp;

	if (a && *a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
	}
}

void	ft_sb(t_stack **b)
{
	t_stack	*tmp;

	if (b && *b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*b)->next;
		(*b)->next = tmp;
	}
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a);
	ft_sb(b);
}
