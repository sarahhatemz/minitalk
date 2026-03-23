/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salzghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:12:25 by salzghou          #+#    #+#             */
/*   Updated: 2025/08/12 19:14:13 by salzghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}
/*
int	main(void){

const char* str = "GeeksforGeeks";
char	ch = 's';
const char* result = ft_strchr(str, ch);

	if (result != NULL) {
		printf("Character '%s'",result);
	}
	else {
		printf("Character '%c' not found.\n",ch );
	}

	return (0);
}
*/
