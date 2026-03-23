/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salzghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:06:22 by salzghou          #+#    #+#             */
/*   Updated: 2025/08/07 16:42:04 by salzghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
/*
int	main(void)
{
const char* str = "Geeksforgeeks";
char	ch = 'g';
const char* result = ft_strrchr(str, ch);

	if (result != NULL) {
		printf("Character '%s'",result);
	}
	else {
		printf("Character '%c' not found.\n",ch );
	}
}*/
