/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:16:06 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/29 08:36:54 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

int	printf_format(char specifier, va_list arg)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (specifier == 'u')
		count += ft_putunsignbr(va_arg(arg, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_puthex(va_arg(arg, unsigned int), specifier);
	else if (specifier == 'p')
		count += ft_putptr(va_arg(arg, void *));
	else if (specifier == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;
	int		i;

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			count += printf_format(format[i + 1], arg);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
/* int main()
{
	ft_printf("%d", 1234);
} */
