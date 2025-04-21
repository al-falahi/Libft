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

static int	ft_word_count(const char *s, char c)
{
	int	count;
	int	in_word;

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

static char	*ft_word_dup(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	ft_free_all(char **arr, int size)
{
	while (size--)
		free(arr[size]);
	free(arr);
}

static int	ft_fill_words(char **res, const char *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = -1;
	while (s[i])
	{
		if (s[i] != c && start < 0)
			start = i;
		if ((s[i] == c || s[i + 1] == '\0') && start >= 0)
		{
			if (s[i + 1] == '\0' && s[i] != c)
				i++;
			res[j] = ft_word_dup(s, start, i);
			if (!res[j])
				return (-1);
			j++;
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
	int		words;

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
