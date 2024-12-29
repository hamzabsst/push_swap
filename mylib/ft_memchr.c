/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:27:05 by hbousset          #+#    #+#             */
/*   Updated: 2024/10/31 11:02:06 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*src;

	src = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
		{
			return ((void *)&src[i]);
		}
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>
int main()
{
	const char str[] = "abdo";
	char c = 'd';
	char *result;
	result = ft_memchr(str, c, 2);
	printf("%s", result);
}*/
