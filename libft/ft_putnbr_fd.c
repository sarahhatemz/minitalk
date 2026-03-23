/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:53:09 by salzghou          #+#    #+#             */
/*   Updated: 2026/01/27 22:38:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_putcharr(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	n1;

	n1 = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		n1 = -n1;
	}
	if (n1 >= 0 && n1 <= 9)
	{
		ft_putcharr(n1 + '0', fd);
	}
	if (n1 > 9)
	{
		ft_putnbr_fd(n1 / 10, fd);
		ft_putnbr_fd(n1 % 10, fd);
	}
}
/*int main (){
	ft_putnbr_fd(100,1);
	return(0);
}*/
