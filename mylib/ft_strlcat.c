/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:17:35 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/29 08:36:54 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (!dst && size == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dst_len >= size)
		return (size + src_len);
	while (src[i] && (dst_len + i + 1) < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/* int main()
{
	char dst[] = "hamza";
	char src[] = "me";
	char b[0xF] = "nyan !";
	int c = ft_strlcat(((void*)0), b, 2);
	printf("%d", c);
} */
