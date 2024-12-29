/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:27:05 by hbousset          #+#    #+#             */
/*   Updated: 2024/10/31 11:02:29 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	size;
	char	*results;

	size = ft_strlen(s);
	results = (char *) malloc((size + 1) * sizeof(char));
	if (!results)
		return (NULL);
	i = 0;
	while (s[i])
	{
		results[i] = s[i];
		i++;
	}
	results[i] = '\0';
	return (results);
}
/*#include <stdio.h>
int main()
{
	char *str = "";
	char *c = ft_strdup(str);
	printf("%s", c);
}*/
