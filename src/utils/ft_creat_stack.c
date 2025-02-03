/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:00:40 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/03 09:48:54 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_stack	*ft_push_new(char *str)
{
	t_stack	*node;
	int		content;

	content = ft_atoi(str);
	if (content != ft_atol(str))
	{
		return (NULL);
	}
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->final_index = 0;
	node->head_index = 0;
	node->pos = 0;
	node->next = NULL;
	return (node);
}

t_stack	*ft_push_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_push_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_push_last(*lst);
		tmp->next = new;
	}
}

void	ft_push_clear(t_stack **lst, void (*del)(int))
{
	t_stack	*tmplst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmplst = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmplst;
	}
	*lst = NULL;
}

int	ft_push_size(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
