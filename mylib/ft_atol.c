/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:55:43 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/29 15:16:09 by hbousset         ###   ########.fr       */
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

static int	check_overflow(long result, char digit)
{
	if (result > LONG_MAX / 10)
		return (1);
	if (result == LONG_MAX / 10 && (digit - '0') > LONG_MAX % 10)
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	char	*string;

	result = 0;
	sign = 1;
	string = skip(str);
	if (*string == '-' || *string == '+')
	{
		if (*string++ == '-')
			sign = -1;
	}
	while (*string >= '0' && *string <= '9')
	{
		if (check_overflow(result, *string))
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		result = result * 10 + (*string - '0');
		string++;
	}
	return (result * sign);
}
