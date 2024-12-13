/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:45:15 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/13 18:54:06 by fcretin          ###   ########.fr       */
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

static int	ft_cheak_dup(int)
{

}

static t_stack	**ft_creat_stack(int ac, char **av, t_stack	**head)
{
	t_stack	*node;
	char	**tab;
	int		i;

	while (--ac > 0)
	{
		tab = ft_split(av[ac], ' ');
		if (!tab)
			return (NULL);
		i = 0;
		while (tab[i])
		{
					node = ft_push_lstnew(ft_atoi(tab[i++]));
					if (!node)
					{
						if (head)
							ft_push_lstclear(head, &ft_delete_content);
						ft_free_the_malloc(tab, 0);
						return (NULL);
					}
					ft_push_lstadd_front(head, node);
		}
		ft_free_the_malloc(tab, 0);
	}
	return (head);
}

int	main(int ac, char **av)
{
	t_stack	*head_a;
	t_stack *head_b;
	t_stack	*tmp;

	head_a = NULL;
	head_b = NULL;
	if (!ft_av_correct_input(ac, av))
		return (1);
	ft_creat_stack(ac, av, &head_a);
	if (!head_a)
		return (1);
	tmp = head_a;
	while (tmp)
	{
		printf("ad : %d\n", tmp->content);
		tmp = tmp->next;
	}
	ft_pre_sorting();
	ft_isneg(&head_a, &head_b);
	tmp = head_a;
	printf("\npre_sorting\n\n");
	while (tmp)
	{
		printf("ap A : %d\n", tmp->content);
		tmp = tmp->next;
	}
	tmp = head_b;
	while (tmp)
	{
		printf("ap B : %d\n",tmp->content);
		tmp = tmp->next;
	}
	return (0);
}
