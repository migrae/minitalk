/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:42:53 by mgraefen          #+#    #+#             */
/*   Updated: 2022/11/01 11:33:59 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	detect(char ch, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	i2;

	if (!s1 || !set)
		return (0);
	i = 0;
	i2 = ft_strlen(s1) - 1;
	while (s1[i] && detect(s1[i], set) == 1)
		i++;
	while (i2 > i && detect(s1[i2], set) == 1)
		i2--;
	return (ft_substr(s1, i, (i2 - i + 1)));
}
