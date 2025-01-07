/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:35:50 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/07 13:59:18 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/**
 * @brief Moves the first element from stack b to stack a.
 *        If stack b is empty, the function does nothing.
 */
void	ft_pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (b && *b)
	{
		if (print == 1)
			ft_printf("pa\n");
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
	}
}

/**
 * @brief Moves the first element from stack a to stack b.
 *        If stack a is empty, the function does nothing.
 */
void	ft_pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (a && *a)
	{
		if (print == 1)
			ft_printf("pb\n");
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
	}
}
