/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:10:01 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/29 10:00:35 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

int	ft_putunsignbr(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb > 9)
	{
		size += ft_putnbr(nb / 10);
		size += ft_putchar((nb % 10) + 48);
	}
	else
		size = size + ft_putchar(nb + 48);
	return (size);
}
