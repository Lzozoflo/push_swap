/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:15:41 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/09 15:07:30 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_except_smallest(t_data **data, t_data *the_smallest)
{
	t_data	*tmp;

	while (*data)
	{
		tmp = *data;
		if (tmp != the_smallest)
			free(tmp);
		*data = (*data)->next;
	}
	if (the_smallest)
		the_smallest->next = NULL;
	*data = the_smallest;
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
