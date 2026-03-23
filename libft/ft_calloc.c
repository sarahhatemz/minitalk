/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salzghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 12:32:44 by salzghou          #+#    #+#             */
/*   Updated: 2025/08/17 13:37:46 by salzghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(1);
		return (ptr);
	}
	total = nmemb * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
/*
int	main(void) {
	int *ptr = (int *)calloc(5, sizeof(int));

	// Checking if failed or pass
	if (ptr == NULL) {
		printf("Allocation Failed");
		exit(0);
	}

	// No need to populate as already
	// initialized to 0

	// Print the array
	for (int i = 0; i < 5; i++)
		printf("%d ", ptr[i]);
	return (0);
}
*/
