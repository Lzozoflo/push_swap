/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_stack_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:00:40 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/13 11:36:12 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_push_lstnew(long int content)
{
	t_stack	*node;

	if (content > INT_MAX || content < INT_MIN)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_push_lstaddback(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_push_lstlast(*lst);
		tmp->next = new;
	}
}

void	ft_push_lstclear(t_stack **lst, void (*del)(int))
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

t_stack	*ft_push_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_push_lstsize(t_stack *lst)
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
