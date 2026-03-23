/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:53:06 by salzghou          #+#    #+#             */
/*   Updated: 2026/01/27 22:23:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	long int	num;
	int			count;

	count = 0;
	num = nb;
	if (num < 0)
	{
		count += ft_putchar('-');
		num *= -1;
	}
	if (num >= 0 && num <= 9)
		count += ft_putchar(num + '0');
	if (num > 9)
	{
		count += ft_putnbr(num / 10);
		count += ft_putnbr(num % 10);
	}
	return (count);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_unbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_unbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_puthex(unsigned long n, int is_upper)
{
	int		count;
	char	*base;

	count = 0;
	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex(n / 16, is_upper);
	count += ft_putchar(base[n % 16]);
	return (count);
}
