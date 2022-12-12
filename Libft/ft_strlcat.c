/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:26:18 by mgraefen          #+#    #+#             */
/*   Updated: 2022/11/02 09:19:07 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dst[i] && i < dstsize)
		i++;
	while ((i + i2 + 1) < dstsize && dstsize > 1 && src[i2])
	{
		dst[i + i2] = src[i2];
		i2++;
	}
	if (dstsize != 0 && i < dstsize)
		dst[i + i2] = '\0';
	while (src[i2])
		i2++;
	return (i + i2);
}
