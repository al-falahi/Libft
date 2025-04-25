/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-fala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:13:59 by aal-fala          #+#    #+#             */
/*   Updated: 2025/04/21 16:29:17 by aal-fala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
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
	size_t	len;
	size_t	sublen;
	char	*trimmed;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && is_set(s1[i], set))
		i++;
	j = len;
	while (j > i && is_set(s1[j - 1], set))
		j--;
	sublen = j - i;
	trimmed = (char *)malloc(sizeof(char) * (sublen + 1));
	if (!trimmed)
		return (NULL);
	ft_memcpy(trimmed, s1 + i, sublen);
	trimmed[sublen] = '\0';
	return (trimmed);
}
