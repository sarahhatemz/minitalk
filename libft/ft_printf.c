/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:15:55 by salzghou          #+#    #+#             */
/*   Updated: 2026/01/27 22:22:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *pointer)
{
	unsigned long	p;
	int				counter;

	counter = 0;
	p = (unsigned long)pointer;
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putstr("0x");
	counter = counter + ft_puthex(p, 0);
	return (counter + 2);
}

int	ft_output(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_unbr(va_arg(args, unsigned int));
	else if (specifier == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (specifier == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (specifier == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (specifier == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *f, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, f);
	while (f[i])
	{
		if (f[i] == '%' && f[i + 1])
		{
			count += ft_output(f[i + 1], args);
			i += 2;
		}
		else
		{
			count += ft_putchar(f[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
/* #include <stdio.h>  // Only used for comparing with real printf (optional)


 int main(void)
 {
	ft_printf("%d",43);

}*/
