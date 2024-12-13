/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:36:31 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/13 11:36:28 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmplast;
	int		len_lst;

	len_lst = 0;
	if (a && *a && (*a)->next)
	{
		tmp = *a;
		len_lst = ft_push_lstsize(*a);
		while (--len_lst > 1)
			tmp = tmp->next;
		tmplast = tmp->next;
		tmp = NULL;
		tmplast->next = *a;
		*a = tmplast;
	}
}

void	ft_rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmplast;
	int		len_lst;

	len_lst = 0;
	if (b && *b && (*b)->next)
	{
		tmp = *b;
		len_lst = ft_push_lstsize(*b);
		while (--len_lst > 1)
			tmp = tmp->next;
		tmplast = tmp->next;
		tmp = NULL;
		tmplast->next = *b;
		*b = tmplast;
	}
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rra(a);
	ft_rrb(b);
}
