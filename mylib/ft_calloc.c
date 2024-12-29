/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:21:35 by hbousset          #+#    #+#             */
/*   Updated: 2024/10/31 11:00:08 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*results;

	results = malloc(count * size);
	if (!results)
		return (NULL);
	ft_bzero(results, count * size);
	return (results);
}
/*#include <stdio.h>
#include <stdlib.h>
int main()
{
	size_t count = 10;
	size_t size = sizeof(int);
	int *arr;
	size_t i = 0;

	arr = (int *)ft_calloc(count, size);
	while (i < count)
	{
		printf("%d ", arr[i]);
		i++;
	}
	free(arr);
	return 0;
}*/
/* 	if (count != 0 && size > SIZE_MAX / count)
		return (NULL); */
