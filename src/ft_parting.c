/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:08:38 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/10 18:13:40 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_str_digit(char *str)
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

// int	ft_redundant()
// {

// }

int	ft_parsing(char *str, t_list **lst)
{
	char **tab;
	if (!(ft_is_str_digit(str)))
		return (0);
	tab = ft_split(str, ' ');
	if (!tab)
		return (0);
	// if (!ft_redundant(tab))
	// {
	// 	ft_free_the_malloc(tab, -1);
	// 	return (0);
	// }
	ft_free_the_malloc(tab, 0);
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
