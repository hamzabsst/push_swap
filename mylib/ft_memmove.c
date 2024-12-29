/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:31:12 by hbousset          #+#    #+#             */
/*   Updated: 2024/10/31 11:02:15 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (!d && !s)
		return (0);
	i = 0;
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
		{
			d[n] = s[n];
		}
	}
	return (dest);
}
/*#include <stdio.h>
#include <string.h>
int main() {
    char str[100] = "hamza is him";
    ft_memmove(str + 5, str, 20);
    printf("%s", str);
}
*/
