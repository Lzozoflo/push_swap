/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:08:38 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/11 13:34:04 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] > 47 && str[i] < 58) || str[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

char	ft_redundant(t_list **lst, t_list *newnode)
{
	t_list *tmp;

	tmp = *lst;
	while (!tmp)
	{
		if (tmp->content == newnode->content)
		{
			ft_lstclear(lst, free);
			return (0);
		}
		tmp = tmp->next;
	}
	ft_lstadd_back(lst, newnode);
	return (1);
}

t_list	*ft_content_node(char *str)
{
	t_list	*newnode;
	int		*content;

	content = ft_atoi_alloc(str);
	if (!newnode)
	{
		return (NULL);
	}
	newnode = ft_lstnew(content);
	if (!newnode)
	{
		free(content);
		return (NULL);
	}
	return (newnode);
}

t_list	*ft_lst_set_fill(char **tab)
{
	t_list	*head;
	t_list	*newnode;
	int		i;

	i = 0;
	head = NULL;
	while (tab[i])
	{
		newnode = ft_content_node(tab[i]);
		if (!newnode)
		{
			if (head)
				ft_lstclear(&head, free);
			return (NULL);
		}
		if (!ft_redundant(&head, newnode))
			return (NULL);
	}
	return (head);
}

int	ft_parsing(char *str, t_list **lst)
{
	t_list	*head;
	char	**tab;

	if (!(ft_is_str_digit(str)))
		return (0);
	tab = ft_split(str, ' ');
	if (!tab)
		return (0);
	head = ft_lst_set_fill(tab);

	ft_free_the_malloc(tab, 0);
	// if (!ft_redundant(tab))
	// {
	// 	ft_free_the_malloc(tab, -1);
	// 	return (0);
	// }
	// printf("\n tab : %s \n" ,tab[0]);
	// printf("\n tab : %s \n" ,tab[1]);
	// printf("\n tab : %s \n" ,tab[2]);
	// printf("\n tab : %s \n" ,tab[3]);
	return (1);
}

// int	main(int agrc,char **agrv)

int	main(void)
{
	t_list *lst;
	char *str = " 1524 2 773 43";

	printf("%d" , ft_parsing(str, &lst));

	return (0);
}
