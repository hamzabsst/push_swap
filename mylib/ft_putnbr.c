/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:38:05 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/29 10:00:35 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

int	ft_putnbr(int nb)
{
	int	size;

	size = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nb < 0)
	{
		nb = -nb;
		size += write(1, "-", 1);
		size += ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		size += ft_putnbr(nb / 10);
		size += ft_putchar((nb % 10) + 48);
	}
	else
		size += ft_putchar(nb + 48);
	return (size);
}
