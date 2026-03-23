/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salzghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:35:08 by salzghou          #+#    #+#             */
/*   Updated: 2025/08/07 16:38:56 by salzghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*sa;

	sa = (char *)s;
	i = 0;
	while (i < n)
	{
		sa[i] = (char)c;
		i++;
	}
	return (sa);
}
/*
int	main(void)
{
	char	e[];

	e[] = "waweaqd";
	ft_memset(e, '#', 3);
	printf("%s\n", e);  // Output: ###eaqd
	return (0);
}
*/
