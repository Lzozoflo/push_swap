/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_med_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:47:01 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/20 08:51:18 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_med(t_stack *stack, int target)
{
	t_stack	*current;
	t_stack	*compare;
	int		count;

	current = stack;
	while (current)
	{
		count = 0;
		compare = stack;
		while (compare)
		{
			if (current->content > compare->content)
				count++;
			compare = compare->next;
		}
		if (count == target)
			break ;
		current = current->next;
	}
	return (current->content);
}

int	ft_find_median(t_stack *stack, int len)
{
	if (len % 2 == 0)
		len = ft_find_med(stack, len / 2);
	else
		len = ft_find_med(stack, (len - 1) / 2);
	return (len);
}

static t_stack	*ft_still_lower_median(t_stack *lst, int median)
{
	while (lst)
	{
		if (lst->content < median)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_med_sort_a(t_stack **a, t_stack **b)
{
	int	len;
	int	med;

	len = ft_push_size(*a);
	med = ft_find_median(*a, len);
	printf("------Médiane calculée : %d-----\n\n", med);
	while (ft_still_lower_median(*a, med))
	{
		if ((*a)->content < med)
			ft_pb(a, b, 1);
		else if ((*a)->next->content < med)
			ft_sa(a, 1);
		else
			ft_ra(a, 1);
		len--;
	}
	ft_print_two_stack(*a, *b);
	printf("\n");
}

// t_stack	*ft_still_higher_median(t_stack *lst, int median)
// {
// 	while (lst)
// 	{
// 		if (lst->content > median)
// 			return (lst);
// 		lst = lst->next;
// 	}
// 	return (NULL);
// }

// void	ft_med_sort_b(t_stack **a, t_stack **b)
// {
// 	int	len;
// 	int	med;

// 	len = ft_push_size(*b);
// 	med = ft_find_median(*b, len);
// 	printf("------Médiane calculée : %d-----\n\n", med);
// 	while (ft_still_higher_median(*b, med))
// 	{
// 		if ((*b)->content > med)
// 			ft_pa(a, b, 1);
// 		else if ((*b)->next->content > med)
// 			ft_sb(b, 1);
// 		else
// 			ft_rb(b, 1);
// 		len--;
// 	}
// 	ft_print_two_stack(*a, *b);
// 	printf("\n");
// }
// void ft_idk(void)
// {

// }
