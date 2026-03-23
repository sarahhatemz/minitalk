/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salzghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:41:32 by salzghou          #+#    #+#             */
/*   Updated: 2025/08/07 17:10:07 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*bi;
	char	*li;

	bi = (char *)big;
	li = (char *)little;
	i = 0;
	if (little[i] == '\0')
		return (bi);
	while (bi[i] && i < len)
	{
		j = 0;
		while (bi[i + j] && li[j] && bi[i + j] == li[j] && (i + j) < len)
		{
			if (li[j + 1] == '\0')
				return (&bi[i]);
			j++;
		}
		i++;
	}
	return (0);
}
/*int main(){

char *s="sarah";
char *f="saz";
printf("%s",ft_strnstr(s,f,4));
}*/
