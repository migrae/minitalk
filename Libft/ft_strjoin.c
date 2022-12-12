/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:00:10 by mgraefen          #+#    #+#             */
/*   Updated: 2022/11/01 11:29:34 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sub;
	size_t	i;
	size_t	i2;

	if (!s1 || !s2)
		return (0);
	i = 0;
	i2 = 0;
	sub = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (sub == 0)
		return (0);
	if (*s1 == '\0' && *s2 == '\0')
	{
		ft_bzero(sub, 1);
		return (sub);
	}
	while (i < ft_strlen(s1))
	{
		sub[i] = s1[i];
		i++;
	}
	while (i2 < ft_strlen(s2))
		sub[i++] = s2[i2++];
	sub[i] = '\0';
	return (sub);
}
