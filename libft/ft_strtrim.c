/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salzghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:10:47 by salzghou          #+#    #+#             */
/*   Updated: 2025/08/12 15:40:03 by salzghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	find(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && find(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && find(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}
/*int	main(void)
{
char s[]="arasarahaaara";
char se[]="sa";
printf("%s",ft_strtrim(s,se));
}*/
