/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:42:24 by mgraefen          #+#    #+#             */
/*   Updated: 2022/11/02 09:21:19 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (size && count > SIZE_MAX / size)
		return (0);
	str = (void *) malloc(size * count);
	if (str == 0)
		return (0);
	while (i < size * count)
			str[i++] = '\0';
	return ((void *) str);
}
