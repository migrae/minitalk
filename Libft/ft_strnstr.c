/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:24:03 by mgraefen          #+#    #+#             */
/*   Updated: 2022/11/02 09:18:43 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (!haystack && len == 0)
		return (0);
	if (needle[i] == '\0' || needle == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		i2 = 0;
		if (needle[i2] == haystack[i])
		{
			while (needle[i2] == haystack[i + i2] && (i + i2) < len)
			{
				if (needle[i2 + 1] == '\0')
					return ((char *)haystack + i);
				i2++;
			}	
		}
		i++;
	}
	return (0);
}
