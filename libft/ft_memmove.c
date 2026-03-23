/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salzghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:41:04 by salzghou          #+#    #+#             */
/*   Updated: 2025/08/09 17:55:22 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	if (d == s || n == 0)
		return (dest);
	if (d < s || d >= (s + n))
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d >= s)
	{
		while (n--)
			d[n] = s[n];
	}
	return (d);
}
/*int main()
{
	char str1[] = "Geeks";
		char str2[] = "Quiz";

	printf("str1 before memmove%s ",str1);


	ft_memmove(str1, str2, sizeof(str2));

	printf("\nstr1 after memmove %s",str1);
	}*/
