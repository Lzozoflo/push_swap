/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:45:15 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/19 19:02:41 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	ft_digit_sign(char *str)
{
	char	*start;

	start = str;
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else if (*str == ' ')
			str++;
		else if (*str == '-' || *str == '+')
		{
			if (ft_isdigit(*(str + 1)) && (str == start || *(str - 1) == ' '))
				str++;
			else
				return (0);
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

static int	ft_av_correct_input(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 1)
		return (0);
	while (--ac > 0)
	{
		if (!ft_digit_sign(av[ac]))
			return (0);
	}
	return (1);
}

static int	ft_cheak_dup(t_stack **head, char *tab)
{
	t_stack	*node;
	t_stack	*tmp;

	tmp = *head;
	node = ft_push_new(tab);
	if (!node)
	{
		if (head)
			ft_push_clear(head, &ft_delete_content);
		return (0);
	}
	while (tmp)
	{
		if (tmp->content == node->content)
		{
			ft_push_clear(head, &ft_delete_content);
			return (0);
		}
		tmp = tmp->next;
	}
	ft_push_add_front(head, node);
	return (1);
}

static t_stack	**ft_creat_stack(int ac, char **av, t_stack	**head)
{
	int		i;
	char	**tab;

	tab = NULL;
	while (--ac > 0)
	{
		tab = ft_split(av[ac], ' ');
		if (!tab)
			return (NULL);
		i = 0;
		while (tab[i])
		{
			if (!ft_cheak_dup(head, tab[i++]))
			{
				ft_free_the_malloc(tab, 0);
				return (NULL);
			}
		}
		ft_free_the_malloc(tab, 0);
	}
	// ft_add_pos(*head);
	return (head);
}

int	main(int ac, char **av)
{
	t_stack	*head_a;
	t_stack *head_b;

	head_a = NULL;
	head_b = NULL;
	if (!ft_av_correct_input(ac, av))
		return (1);
	if (!ft_creat_stack(ac, av, &head_a))
		return (1);
	test_to_print_lst(&head_a, &head_b);














	return (0);
}
