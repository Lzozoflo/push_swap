/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:36:16 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/13 11:34:48 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmplast;

	if (a && *a && (*a)->next)
	{
		tmp = (*a);
		*a = (*a)->next;
		tmplast = ft_push_lstlast(*a);
		tmplast->next = tmp;
		tmp = tmplast->next;
	}
}

void	ft_rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmplast;

	if (b && *b && (*b)->next)
	{
		tmp = (*b);
		*b = (*b)->next;
		tmplast = ft_push_lstlast(*b);
		tmplast->next = tmp;
		tmp = tmplast->next;
	}
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a);
	ft_rb(b);
}
