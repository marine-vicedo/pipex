/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:20:42 by mvicedo           #+#    #+#             */
/*   Updated: 2022/05/25 15:31:36 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	if (s == 0)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			res[j++] = s[i];
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}
