/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:10:13 by mvicedo           #+#    #+#             */
/*   Updated: 2022/05/25 13:56:49 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char sep)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == sep)
				i++;
		if (s[i])
				count++;
		while (s[i] && s[i] != sep)
				i++;
	}
	return (count);
}

static size_t	ft_wordlen(char const *src, char sep, size_t index)
{
	size_t	len;

	len = 0;
	while (src[index] && src[index] != sep)
	{
		len++;
		index++;
	}
	return (len);
}

static char	*ft_fillwords(char const *s, char sep, size_t index)
{
	char	*word;
	size_t	wordlen;
	size_t	j;

	j = 0;
	wordlen = ft_wordlen(s, sep, index);
	word = (char *)malloc(sizeof(char) * (wordlen + 1));
	if (!word)
		return (NULL);
	while (j < wordlen)
	{
		word[j] = s[index];
		index++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char sep)
{
	char	**tab;
	size_t	tab_size;
	size_t	cell;
	size_t	i;

	i = 0;
	cell = 0;
	tab_size = ft_countwords(s, sep);
	tab = (char **)malloc(sizeof(char *) * (tab_size + 1));
	if (tab == 0)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == sep)
			i++;
		if (s[i])
		{
			tab[cell] = ft_fillwords(s, sep, i);
			cell++;
		}
		while (s[i] && s[i] != sep)
			i++;
	}
	tab[cell] = NULL;
	return (tab);
}
