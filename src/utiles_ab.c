/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_a_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 08:30:39 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/10 16:31:56 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_s_ab(t_list **a_b)
{
	t_list	*tmp;

	if (a_b && *a_b && (*a_b)->next)
	{
		tmp = *a_b;
		a_b = (*a_b)->next;
		tmp->next = (*a_b)->next;
		(*a_b)->next = tmp;
	}
}

void	ft_p_ab(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (b && *b)
	{
		tmp = (*a);
		(*a) = (*b);
		b = (*b)->next;
		(*b)->next = tmp;
	}
}

void	ft_r_ab(t_list **a)
{
	t_list	*tmp;
	t_list	*tmplast;

	if (a && *a && (*a)->next)
	{
		tmp = (*a);
		(*a) = (*a)->next;
		tmplast = ft_lstlast(*a);
		tmp = tmplast->next;
		tmplast->next = tmp;
	}
}

void	ft_rr_ab(t_list **a)
{
	t_list	*tmp;
	t_list	*tmplast;
	int		len_lst;

	len_lst = 0;
	if (a && *a && (*a)->next)
	{
		len_lst = ft_lstsize(*a);
		tmp = *a;
		while (--len_lst > 1)
			tmp = tmp->next;
		tmplast = tmp->next;
		tmp = NULL;
		tmplast->next = *a;
		*a = tmplast;
	}
}
