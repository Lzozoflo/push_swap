/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:25:55 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/14 10:31:34 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	pos(tmp)
{
	int	i;

	i = 0;
	while ()
	{

	}
}

void	ft_add_pos(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*tmpswap;
	int		nbpos;
	int		i;

	tmpswap = NULL;
	i = 0;
	nbpos = ft_push_size(*head);
	while (nbpos > i)
	{
		tmp = *head;
		while (tmp)
		{
			if (tmp->content > tmp->next->content)
			{
				tmpswap = tmp;
				tmp = tmp->next;
				tmpswap->next = tmp->next;
				tmp->next = tmpswap;
			}
			tmp = tmp->next;
		}
		i++;
	}
	pos(tmp);
}
