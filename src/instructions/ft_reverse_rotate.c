/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:36:31 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/19 18:07:35 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_rra(t_stack **a, int print)
{
	t_stack	*last;
	t_stack	*tmp;

	if (a && *a && (*a)->next)
	{
		if (print == 1)
			ft_printf("rra\n");
		last = *a;
		while (last->next)
		{
			tmp = last;
			last = last->next;
		}
		tmp->next = NULL;
		last->next = *a;
		*a = last;
	}
}

void	ft_rrb(t_stack **b, int print)
{
	t_stack	*last;
	t_stack	*tmp;

	if (b && *b && (*b)->next)
	{
		if (print == 1)
			ft_printf("rrb\n");
		last = *b;
		while (last->next)
		{
			tmp = last;
			last = last->next;
		}
		tmp->next = NULL;
		last->next = *b;
		*b = last;
	}
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rra(a,0);
	ft_rrb(b,0);
	ft_printf("rrr\n");
}
