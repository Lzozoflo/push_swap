/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:15:41 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/15 09:33:20 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_except_smallest(t_data **data, t_data *the_smallest)
{
	t_data	*tmp;
	t_data	*current;

	if (!data || !*data)
		return ;
	current = *data;
	while (current)
	{
		tmp = current;
		current = current->next;
		if (tmp != the_smallest)
			free(tmp);
	}
	if (the_smallest)
		the_smallest->next = NULL;
	*data = the_smallest;
}

void	ft_free_data(t_data **data)
{
	t_data	*tmp;

	if (!data || !*data)
		return ;
	while (tmp)
	{
		tmp = *data;
		*data = (*data)->next;
		free(tmp);
	}
	*data = NULL;
}

int	ft_free_stack(t_stack **head, int error)
{
	t_stack	*tmp;

	while (head && *head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	*head = NULL;
	return (error);
}

int	ft_free_all(t_stack **a, t_stack **b, t_data **data)
{
	ft_free_data(data);
	ft_free_stack(b, 1);
	ft_free_stack(a, 1);
	return (0);
}
