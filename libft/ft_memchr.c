/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salzghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:45:39 by salzghou          #+#    #+#             */
/*   Updated: 2025/08/09 18:21:58 by salzghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cc;
	size_t			i;

	str = (unsigned char *)s;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == cc)
			return (&str[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{

	char str[] = "Hello, World!";
char	*result3 = ft_memchr(str, 'W', 5);
	if (result3 == NULL)
		printf("Test 3 Passed: 'W' not found in first 5 bytes as expected\n");
	else
		printf("Test 3 Failed: Unexpectedly found '%c'\n", *result3);

}*/
