/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:28:29 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/19 18:07:26 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_sa(t_stack **a, int print)
{
	t_stack	*tmp;

	if (a && *a && (*a)->next)
	{
		if (print == 1)
			ft_printf("sa\n");
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
	}
}

void	ft_sb(t_stack **b, int print)
{
	t_stack	*tmp;

	if (b && *b && (*b)->next)
	{
		if (print == 1)
			ft_printf("sb\n");
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*b)->next;
		(*b)->next = tmp;
	}
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	ft_printf("ss\n");
}
