/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_and_more.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:19:24 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/22 16:00:32 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	ft_find_index_min(t_stack *a, int *index_min)
{
	int	min;
	int	index;

	index = 0;
	min = INT_MAX;
	while (a)
	{
		if (a->content < min)
		{
			min = a->content;
			*index_min = index;
		}
		index++;
		a = a->next;
	}
}

static void	ft_mouve_min(t_stack **a, t_stack **b, int min_i)
{
	int	size;

	size = ft_push_size(*a);
	if (min_i <= (size / 2))
		while (min_i-- > 0)
			ft_ra(a, 1);
	else
		while (min_i++ < size)
			ft_rra(a, 1);
	ft_pb(a, b, 1);
}

static void	ft_sort_three(t_stack **a)
{
	if ((*a)->content < (*a)->next->content
		&& (*a)->next->content < (*a)->next->next->content)
		return ;
	else if ((*a)->content > (*a)->next->content
		&& (*a)->content < (*a)->next->next->content)
		ft_sa(a, 1);
	else if ((*a)->content > (*a)->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		ft_ra(a, 1);
		ft_sa(a, 1);
	}
	else if ((*a)->content > (*a)->next->next->content
		&& (*a)->next->content < (*a)->next->next->content)
		ft_ra(a, 1);
	else if ((*a)->content < (*a)->next->content
		&& (*a)->content > (*a)->next->next->content)
		ft_rra(a, 1);
	else if ((*a)->content < (*a)->next->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		ft_sa(a, 1);
		ft_ra(a, 1);
	}
}

static int	ft_sort_modular(t_stack **a, t_stack **b, int nbr_to_sort)
{
	int	n_to_sort;
	int	index_min;

	n_to_sort = nbr_to_sort;
	while (nbr_to_sort-- > 0)
	{
		ft_find_index_min(*a, &index_min);
		ft_mouve_min(a, b, index_min);
	}
	ft_sort_three(a);
	while (n_to_sort-- > 0)
		ft_pa(a, b, 1);
	return (1);
}

int	ft_little_sort(t_stack **a, t_stack **b, int len)
{
	if (len == 1)
		return (1);
	else if (len == 2 && (*a)->content > (*a)->next->content)
	{
		ft_sa(a, 1);
		return (1);
	}
	else if (len == 2)
		return (1);
	else if (len == 3)
	{
		ft_sort_three(a);
		return (1);
	}
	else if (len == 4)
		return (ft_sort_modular(a, b, 4 - 3));
	else if (len == 5)
		return (ft_sort_modular(a, b, 5 - 3));
	else if (len == 6)
		return (ft_sort_modular(a, b, 6 - 3));
	return (0);
}
