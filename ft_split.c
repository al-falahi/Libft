/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-fala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:48:40 by aal-fala          #+#    #+#             */
/*   Updated: 2025/04/21 19:21:18 by aal-fala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_word_dup(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	len;

	len = end - start;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s + start, len);
	word[len] = '\0';
	return (word);
}

static void	ft_free_all(char **arr, size_t size)
{
	while (size--)
		free(arr[size]);
	free(arr);
}

static int	ft_fill_words(char **res, const char *s, char c)
{
	size_t	i;
	size_t	j;
	ssize_t	start;
	size_t	end;

	i = 0;
	j = 0;
	start = -1;
	while (s[i])
	{
		if (s[i] != c && start < 0)
			start = (ssize_t)i;
		if ((s[i] == c || s[i + 1] == '\0') && start >= 0)
		{
			if (s[i] == c)
				end = i;
			else
				end = i + 1;
			res[j] = ft_word_dup(s, (size_t)start, end);
			if (!res[j++])
				return (-1);
			start = -1;
		}
		i++;
	}
	res[j] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_word_count(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	if (ft_fill_words(res, s, c) == -1)
	{
		ft_free_all(res, words);
		return (NULL);
	}
	return (res);
}
