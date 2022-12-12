/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:01:37 by mgraefen          #+#    #+#             */
/*   Updated: 2022/11/01 11:28:51 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_skip(char *s, char c, int i)
{
	while (*s != '\0' && *s == c && i == 1)
		s++;
	while (*s != '\0' && *s != c && i == 0)
		s++;
	return (s);
}

int	ft_count_word(char *s, char c)
{
	int	i;

	i = 0;
	s = ft_skip(s, c, 1);
	while (*s != '\0')
	{
		s = ft_skip(s, c, 0);
		s = ft_skip(s, c, 1);
		i++;
	}
	return (i);
}

static char	**ft_free(char **out)
{
	int	i;

	i = 0;
	while (out[i])
	{
		free(out[i]);
		i++;
	}
	free(out);
	return (0);
}

static char	*ft_wordcut(char *s, char c)
{
	int		i;
	char	*out;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	out = ft_calloc(i + 1, sizeof(char));
	if (out == 0)
		return (0);
	i = 0;
	while (s[i] != c && s[i])
	{
		out[i] = s[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**out;
	char	*cpy;

	i = 0;
	if (s == 0)
		return (0);
	out = ft_calloc(ft_count_word((char *) s, c) + 1, sizeof(char *));
	if (out == 0)
		return (0);
	if (ft_strlen(s) == 0)
		return (out);
	cpy = (char *)s;
	cpy = ft_skip(cpy, c, 1);
	while (*cpy != '\0')
	{
		out[i] = ft_wordcut(cpy, c);
		if (out[i] == 0)
			return (ft_free(out));
		cpy = ft_skip(cpy, c, 0);
		cpy = ft_skip(cpy, c, 1);
		i++;
	}
	return (out);
}
