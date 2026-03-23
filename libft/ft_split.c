/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salzghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:46:52 by salzghou          #+#    #+#             */
/*   Updated: 2025/08/16 13:03:39 by salzghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	count(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static void	freeee(char **words, int n)
{
	while (n > 0)
	{
		n--;
		free(words[n]);
	}
	free(words);
}

static char	*alloc_word(const char *s, int start, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_split_loop(char **res, const char *s, char c)
{
	int	i;
	int	k;
	int	start;
	int	len;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		len = i - start;
		if (len > 0)
		{
			res[k] = alloc_word(s, start, len);
			if (!res[k])
				return (freeee(res, k), -1);
			k++;
		}
	}
	res[k] = NULL;
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc((count(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (ft_split_loop(res, s, c) == -1)
		return (NULL);
	return (res);
}
/*
int main(void)
{
	char **words = ft_split("to live for the hope of it all",
			' '); for (int i = 0; words[i]; i++)
	printf("[%s]\n", words[i]);
	return (0);
	}*/
