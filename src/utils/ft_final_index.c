/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:13:58 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/08 19:06:46 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_higher(t_stack *lst, int content)
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