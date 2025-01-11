/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:16:02 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/11 15:28:16 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_the_end(t_stack **a, t_stack **b)
{
	t_stack	*last;

	last = ft_push_last(*a);
	while (*b)
	{
		if (last->final_index - 1 == (*b)->final_index)
		{
			ft_rra(a, 1);
			last = ft_push_last(*a);
		}
		else
		{
			ft_pa(a, b, 1);
		}
	}
}

// void	ft_the_end(t_stack **a, t_stack **b)
// {
// 	t_stack	*last;

// 	last = ft_push_last(*a);
// 	while (b)
// 	{
// 		if (last->final_index - 1 == (*b)->final_index)
// 		{
// 			printf("%d", last->final_index);
// 			ft_rra(a, 1);
// 			last = ft_push_last(*a);
// 			printf("%d", last->final_index);
// 		}
// 		else
// 		{
// 			printf("%d", last->final_index);
// 			ft_pa(a, b, 1);
// 		}
// 	}
// }
