/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:46:43 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/29 08:36:54 by hbousset         ###   ########.fr       */
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

int	ft_atoi(const char	*str)
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
	return ((int)result * sign);
}
/* int main()
{
	char *str = "-11111111";
	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
} */
