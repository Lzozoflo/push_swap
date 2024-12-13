/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:36:16 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/13 13:49:27 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (a && *a && (*a)->next)
	{
		tmp = (*a);
		*a = (*a)->next;
		last = ft_push_lstlast(*a);
		tmp->next = NULL;
		last->next = tmp;
	}
}

void	ft_rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (b && *b && (*b)->next)
	{
		tmp = (*b);
		*b = (*b)->next;
		last = ft_push_lstlast(*b);
		tmp->next = NULL;
		last->next = tmp;
	}
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a);
	ft_rb(b);
}
