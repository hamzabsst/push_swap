/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:21:55 by hbousset          #+#    #+#             */
/*   Updated: 2024/10/31 11:02:25 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>
int main()
{
	int z;
	char *c = strchr("opaeee", z);
	printf("%s", c);
	printf("\n");
	char *d = ft_strchr("opaeee", z);
	printf("%s", d);
}*/
