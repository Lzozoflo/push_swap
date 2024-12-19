/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:47:01 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/19 19:42:00 by fcretin          ###   ########.fr       */
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

// int	ft_more_higher(t_stack *stack, int med)
// {
// 	int		pos;
// 	t_stack	*current;

// 	pos = 0;
// 	current = stack;
// 	while (current)
// 	{
// 		if (current->content <= med)
// 			return (pos);
// 		pos++;
// 		current = current->next;
// 	}
// 	printf("-1");
// 	return (-1);
// }

// void	ft_pre_sort(t_stack **a, t_stack **b)
// {
// 	int	len;
// 	int	med;

// 	len = ft_push_size(*a);
// 	med = ft_find_median(*a, len);
// 	printf("\n med :%d\n", med);
// 	while (!ft_more_higher(*a, med))
// 	{
// 		if ((*a)->content > med)
// 		{
// 			ft_pb(a, b, 1);
// 			if ((*b)->content > ft_push_last(*b)->content)
// 				ft_rb(b, 1);
// 			len--;
// 		}
// 		else
// 			ft_ra(a, 1);
// 		// if (*b && (*b)->next)
// 		// 	if ((*b)->content > (*b)->next->content)
// 		// 		ft_sb(b, 1);
// 	}
// }

t_stack	*ft_lst_find_below_median(t_stack *lst, int median)
{
	while (lst)
	{
		if (lst->content < median)
			return (lst); // Retourne le nœud trouvé
		lst = lst->next;
	}
	return (NULL); // Aucun nœud trouvé en dessous de la médiane
}



void	ft_pre_sort(t_stack **a, t_stack **b)
{
	int	len;
	int	med;

	len = ft_push_size(*a);
	med = ft_find_median(*a, len);
	printf("Médiane calculée : %d\n\n", med);
	while (ft_lst_find_below_median(*a, med))
	{
		// ft_print_two_stack(*a, *b);
		if ((*a)->content < med)
		{
			// printf("Pousser %d dans B\n", (*a)->content);
			ft_pb(a, b, 1);
		}
		else if ((*a)->next->content < med)
			ft_sa(a, 1);
		else
		{
			// printf("Faire tourner A\n");
			ft_ra(a, 1);
		}
		len--;
	}
	printf("fin\n");
}









// void	ft_isneg(t_stack **a, t_stack **b)
// {
// 	int	len;

// 	len = ft_push_size(*a);
// 	while (len > 0)
// 	{
// 		if ((*a)->content < 0)
// 			ft_pb(a, b, 1);
// 		else
// 			ft_ra(a, 1);
// 		len--;
// 	}
// }




// void ft_idk(void)
// {

// }
