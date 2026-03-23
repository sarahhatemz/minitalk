/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salzghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:50:59 by salzghou          #+#    #+#             */
/*   Updated: 2025/08/11 14:49:05 by salzghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	i;
	char	*result;

	s1len = ft_strlen(s1);
	if (!s1 || !s2)
		return (NULL);
	result = malloc(s1len + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		result[s1len + i] = s2[i];
		i++;
	}
	result[s1len + i] = '\0';
	return (result);
}
/*
int	main(void)
{

	char a[]="sarah";
	char b[]="hatem";
	printf("%s",ft_strjoin(a,b));


}*/
