/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:55:43 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/29 13:03:58 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

static char	*skip(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return ((char *)str + i);
}

long	ft_atol(const char	*str)
{
	long	result;
	int		sign;
	long	max;
	char	*string;

	result = 0;
	sign = 1;
	max = 0;
	string = skip(str);
	if (*string == '-' || *string == '+')
		if (*string++ == '-')
			sign = -1;
	while (*string >= '0' && *string <= '9')
	{
		result = result * 10 + *string - 48;
		if (result < max)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		string++;
		max = result;
	}
	return (result * sign);
}
