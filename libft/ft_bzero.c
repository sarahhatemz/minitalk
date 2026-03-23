/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salzghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:25:57 by salzghou          #+#    #+#             */
/*   Updated: 2025/08/07 16:37:02 by salzghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	buffer[10];

	buffer[10] = "abcdefghi";
	printf("Before ft_bzero: ");
	for (int i = 0; i < 10; i++)
	{
		if (buffer[i] == '\0')
			printf("\\0 ");
		else
			printf("%c ", buffer[i]);
	}
	printf("\n");
	// Zero out the first 5 bytes
	ft_bzero(buffer, 5);
	printf("After ft_bzero (first 5 bytes): ");
	for (int i = 0; i < 10; i++)
	{
		if (buffer[i] == '\0')
			printf("\\0 ");
		else
			printf("%c ", buffer[i]);
	}
	printf("\n");
	return (0);
}
*/
