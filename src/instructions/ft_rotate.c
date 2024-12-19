/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:36:16 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/19 18:07:32 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_ra(t_stack **a, int print)
{
	t_stack	*tmp;

	if (!(a && *a && (*a)->next))
		return ;
	if (print == 1)
		ft_printf("ra\n");
	tmp = (*a);
	*a = (*a)->next;
	ft_push_last(*a)->next = tmp;
	tmp->next = NULL;
}

void	ft_rb(t_stack **b, int print)
{
	t_stack	*tmp;

	if (!(b && *b && (*b)->next))
		return ;
	if (print == 1)
		ft_printf("rb\n");
	tmp = (*b);
	*b = (*b)->next;
	ft_push_last(*b)->next = tmp;
	tmp->next = NULL;
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a,0);
	ft_rb(b,0);
	ft_printf("rr\n");
}
