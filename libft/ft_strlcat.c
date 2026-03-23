/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salzghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:47:09 by salzghou          #+#    #+#             */
/*   Updated: 2025/08/07 16:39:41 by salzghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	d;
	size_t	i;

	s = 0;
	d = 0;
	i = 0;
	while (dst[d])
		d++;
	while (src[s])
		s++;
	if (d >= size)
		return (size + s);
	while (src[i] && (d + i) < size - 1)
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (s + d);
}
/*
int	main(void){

char	first[] = "sadeen";
char	last[] = "dalal";
ft_strlcat(last,first,30);
printf("%s",last);
return(0);}*/
