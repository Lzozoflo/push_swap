/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turc_sort_mouve.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:03:00 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/10 17:42:18 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_equal_top_to_bot(t_stack **a, t_stack **b, t_data **data)
{
	while (ft_equal_or_not(a, b, data))
		ft_rr(a, b);
	return (1);
}

int	ft_equal_bot_to_top(t_stack **a, t_stack **b, t_data **data)
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
