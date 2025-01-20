/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:08:02 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/15 13:38:56 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_ahia(t_stack *lst, int size, int *i)
{
	if (size % 2 == 0)
	{
		lst->head_index = (*i)--;
		lst->pos = 0;
	}
	if (size % 2 == 1)
	{
		lst->head_index = --(*i);
		lst->pos = -1;
	}
}

static void	ft_add_head_index_a(t_stack *lst)
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
		lst->pos = 1;
		lst = lst->next;
	}
	ft_ahia(lst, size, &i);
	lst = lst->next;
	while (lst)
	{
		if (size % 2 == 0)
			lst->head_index = i--;
		else
			lst->head_index = --i;
		lst->pos = -1;
		lst = lst->next;
	}
}

static void	ft_adib(t_stack *lst, int size, int *i)
{
	if (size % 2 == 0)
		lst->head_index = (*i)--;
	if (size % 2 == 1)
	{
		lst->head_index = (*i);
		lst->pos = 1;
	}
}

static void	ft_add_head_index_b(t_stack *lst)
{
	int	i;
	int	size;
	int	med;

	i = 0;
	size = ft_push_size(lst);
	med = (size) / 2;
	while (i < med && lst)
	{
		lst->head_index = i++;
		lst->pos = 1;
		lst = lst->next;
	}
	ft_adib(lst, size, &i);
	lst = lst->next;
	while (lst != NULL)
	{
		lst->head_index = i--;
		lst->pos = -1;
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
