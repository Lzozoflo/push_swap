/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_four_five.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:19:24 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/20 11:34:26 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

static void	ft_sort_four(t_stack **a, t_stack **b)
{
	int	min1;
	int	index_1;

	min1 = ft_find_index_min(*a, &index_1);
	ft_mouve_min(a, b, index_1);
	ft_sort_three(a);
	ft_pa(a, b, 1);
}

static void	ft_sort_five(t_stack **a, t_stack **b)
{
	int	min1;
	int	index_1;
	int	index_2;

	min1 = ft_find_index_min(*a, &index_1);
	ft_mouve_min(a, b, index_1);
	ft_find_index_second_min(*a, min1, &index_2);
	ft_mouve_min(a, b, index_2);
	ft_sort_three(a);
	ft_pa(a, b, 1);
	ft_pa(a, b, 1);
}

void	ft_little_sort(t_stack **a, t_stack **b, int len)
{
	if (len == 2 && (*a)->content > (*a)->next->content)
		ft_sa(a, 1);
	else if (len == 2)
		return ;
	else if (len == 3)
		ft_sort_three(a);
	else if (len == 4)
		ft_sort_four(a, b);
	else if (len == 5)
		ft_sort_five(a, b);
}

void	ft_pre_sort(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_push_size(*a);
	printf("\n-------------Start pre_sorting-------------\n\n");
	ft_med_sort(a, b);
	// ft_med_sort_b(a, b);
	while (len > 5)
	{
		len = ft_push_size(*a);
		if (len < 6)
			break ;
		ft_med_sort(a, b);
	}
	ft_little_sort(a, b, len);
	printf("\n-------------End pre_sorting-------------\n\n");
}



	// len = ft_push_size(*b);
	// 	printf("hum %d",len);
	// while (len > 5)
	// {
	// 	len = ft_push_size(*b);
	// 	if (len < 6)
	// 		break ;
	// 	ft_med_sort_b(a, b);
	// }
	// ft_little_sort(a, b, len);
