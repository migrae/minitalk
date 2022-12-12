/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:16:09 by mgraefen          #+#    #+#             */
/*   Updated: 2022/11/02 09:20:29 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*a;

	a = s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)a[i] == (unsigned char)c)
			return ((void *)&a[i]);
		i++;
	}
	return (0);
}
