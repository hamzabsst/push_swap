/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:53:17 by hbousset          #+#    #+#             */
/*   Updated: 2024/10/31 11:02:09 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
		{
			return (ptr1[i] - ptr2[i]);
		}
		i++;
	}
	return (0);
}
/*#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int main()
{
    const char str1[] = "hamza89";
    const char str2[] = "hamza";
    int result;
    result = ft_memcmp(str1, str2, strlen(str1));
	printf ("%d", result);
}*/
