/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:45:15 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/05 16:58:28 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	ft_sorted(t_stack *a)
{
	while (a->next)
	{
		if (!(a->final_index < a->next->final_index))
			return (0);
		a = a->next;
	}
	return (1);
}

static int	ft_av_correct_input(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ft_no_input(av))
		return (0);
	while (--ac > 0)
	{
		if (!ft_digit_sign(av[ac]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
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
			free(node);
			return (0);
		}
		tmp = tmp->next;
	}
	ft_push_add_back(head, node);
	return (1);
}

static t_stack	**ft_creat_stack(int ac, char **av, t_stack **head)
{
	int		i;
	int		j;
	char	**tab;

	j = 1;
	tab = NULL;
	while (j < ac)
	{
		tab = ft_split(av[j++], ' ');
		if (!tab)
			return (NULL);
		i = 0;
		while (tab[i])
		{
			if (!ft_cheak_dup(head, tab[i++]))
			{
				ft_freetab(tab, 0);
				return (NULL);
			}
		}
		ft_freetab(tab, 0);
	}
	ft_add_final_index(*head);
	return (head);
}

int	main(int ac, char **av)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (!ft_av_correct_input(ac, av))
		return (1);
	if (!ft_creat_stack(ac, av, &head_a))
	{
		write(2, "Error\n", 6);
		return (ft_free_stack(&head_a, 1));
	}
	if (ft_sorted(head_a))
		return (ft_free_stack(&head_a, 0));
	if (ft_little_sort(&head_a, &head_b, ft_push_size(head_a)))
		return (ft_free_stack(&head_a, 0));
	ft_first_move(&head_a, &head_b);
	ft_sort_to_b(&head_a, &head_b);
	ft_last_move(&head_a, &head_b);
	ft_free_stack(&head_b, 0);
	return (ft_free_stack(&head_a, 0));
}
