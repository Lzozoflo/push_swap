/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:36:31 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/13 14:58:53 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*tmp;

	if (a && *a && (*a)->next)
	{
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

void	ft_rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*tmp;

	if (b && *b && (*b)->next)
	{
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
	ft_rra(a);
	ft_rrb(b);
}
