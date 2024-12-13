/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:47:01 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/13 18:17:54 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_isneg(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_push_lstsize(*a);
	while (len > 0)
	{
		if ((*a)->content < 0)
			ft_pb(a, b);
		else
			ft_ra(a);
		len--;
	}
}

// void ft_idk(void)
// {

// }

// void ft_idk(void)
// {

// }

// void ft_idk(void)
// {

// }

// void ft_idk(void)
// {

// }
