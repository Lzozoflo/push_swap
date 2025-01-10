/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:10:23 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/10 17:36:13 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_while_ra(t_stack **a, t_data **data)
{
	while ((*a)->final_index != (*data)->node_a->final_index)
		ft_ra(a, 1);
}

void	ft_while_rb(t_stack **b, t_data **data)
{
	while ((*b)->final_index != (*data)->node_b->final_index)
		ft_rb(b, 1);
}

void	ft_while_rra(t_stack **a, t_data **data)
{
	while ((*a)->final_index != (*data)->node_a->final_index)
		ft_rra(a, 1);
}

void	ft_while_rrb(t_stack **b, t_data **data)
{
	while ((*b)->final_index != (*data)->node_b->final_index)
		ft_rrb(b, 1);
}
