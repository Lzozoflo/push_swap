/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_head_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:08:02 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/06 16:50:40 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_head_index_a(t_stack *lst)
{
	int	size;
	int	i;
	int	med;

	i = 1;
	size = ft_push_size(lst);
	med = (size + 1) / 2;
	while (i <= med && lst)
	{
		lst->head_index = i++;
		lst = lst->next;
	}
	if (size % 2 == 1)
		i--;
	while (lst)
	{
		lst->head_index = i--;
		lst = lst->next;
	}
}

void	ft_add_head_index_b(t_stack *lst)
{
	int	i;
	int	size;
	int	med;

	i = 0;
	size = ft_push_size(lst);
	med = (size + 1) / 2;
	while (i < med && lst)
	{
		lst->head_index = i++;
		lst = lst->next;
	}
	if (size % 2 == 0)
		lst->head_index = i--;
	if (size % 2 == 1)
		lst->head_index = i;
	lst = lst->next;
	while (lst != NULL)
	{
		lst->head_index = i--;
		lst = lst->next;
	}
}

int	ft_count_higher(t_stack *lst, int content)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		if (lst->content > content)
			count += 1;
		lst = lst->next;
	}
	return (count);
}

void	ft_add_final_index(t_stack *lst)
{
	t_stack	*tmp;
	int		size;

	tmp = lst;
	size = ft_push_size(lst);
	while (lst != NULL)
	{
		lst->final_index = size - ft_count_higher(tmp, lst->content);
		lst = lst->next;
	}
}

void	ft_add_utils(t_stack *a, t_stack *b)
{
	if (a)
		ft_add_head_index_a(a);
	if (b)
		ft_add_head_index_b(b);
}
