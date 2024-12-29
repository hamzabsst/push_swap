/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:51:24 by hbousset          #+#    #+#             */
/*   Updated: 2024/10/31 11:02:58 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = ft_strlen(s);
	while (size >= 0)
	{
		if (s[size] == (char)c)
		{
			return ((char *)s + size);
		}
		size--;
	}
	return (NULL);
}
/*int main()
{
	char *c = strrchr("ahamzaop", 'a');
	printf("%s", c);
	printf("\n");
	char *d = ft_strrchr("ahamzaop", 'a');
	printf("%s", d);

}*/
