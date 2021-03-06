/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:33:47 by rnitta            #+#    #+#             */
/*   Updated: 2020/07/20 20:39:23 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int word;
	int len;

	word = 0;
	len = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (len > 0)
				word++;
			len = 0;
		}
		else
			len++;
		s++;
	}
	if (len > 0)
		word++;
	return (word);
}

char		**ft_split(char const *s, char c)
{
	char	**p;
	int		cnt;
	int		i;
	int		j;

	if (!(p = malloc(sizeof(char*) * (ft_count(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == c)
			j++;
		cnt = j;
		while (s[j] != c && s[j])
			j++;
		if (j > cnt)
			p[i++] = ft_substr(s, cnt, j - cnt);
	}
	p[i] = NULL;
	return (p);
}
