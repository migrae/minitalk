/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:23:18 by mgraefen          #+#    #+#             */
/*   Updated: 2022/11/01 11:29:15 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s1) + 1;
	copy = (char *) ft_calloc(sizeof(char), len);
	if (copy == 0)
		return (0);
	ft_strlcpy(copy, s1, len);
	return ((char *)copy);
}
