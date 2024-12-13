/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:49:15 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/12 17:13:16 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts a string to an integer.
 *
 * The function `ft_atoi` takes a string as input and converts the numeric
 * part of the string into an integer of type `int`. It ignores leading
 * whitespace, handles the signs (+/-), and stops when a non-numeric character
 * is encountered.
 *
 * @param str The string to convert to an integer.
 *
 * @return int The resulting integer from the conversion of the string.
 *             Returns 0 if no digits are present.
 */
long int	ft_atoi(const char *str)
{
	long int	res;
	int			i;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}
