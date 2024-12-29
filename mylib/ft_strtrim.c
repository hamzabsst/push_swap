/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:21:13 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/29 08:36:54 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		i++;
	}
	while (s1[len - 1] && ft_strchr(set, s1[len - 1]))
	{
		len--;
	}
	return (ft_substr(s1, i, len - i));
}
/*int main(void)
{
	char *str = "ababbababababa";
	char *set = "ab";
	char *trimmed_str = ft_strtrim(str, set);
	printf("Trimmed string: '%s'", trimmed_str);
	free(trimmed_str);
}*/
