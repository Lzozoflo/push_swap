/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:54:29 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/22 16:58:37 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_data	*ft_data_last(t_data *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_data	*ft_data_new(void)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->count = INT_MAX;
	new->node_a = NULL;
	new->node_b = NULL;
	new->next = NULL;
	return (new);
}

void	ft_data_add_back(t_data **lst, t_data *new)
{
	t_data	*tmp;

	tmp = NULL;
	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_data_last(*lst);
		tmp->next = new;
	}
}
