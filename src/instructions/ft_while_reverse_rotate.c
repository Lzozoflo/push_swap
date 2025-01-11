/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:03:00 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/11 10:34:27 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_while_rr(t_stack **a, t_stack **b, t_data **data)
{
	while (ft_equal_or_not(a, b, data))
		ft_rr(a, b);
	return (1);
}

int	ft_while_rrr(t_stack **a, t_stack **b, t_data **data)
{
	while (ft_equal_or_not(a, b, data))
		ft_rrr(a, b);
	return (-1);
}

// void	ft_idk(void)
// {

// }

// void	ft_idk(void)
// {

// }

// void	ft_idk(void)
// {

// }
