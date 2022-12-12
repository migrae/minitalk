/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:21:15 by mgraefen          #+#    #+#             */
/*   Updated: 2022/11/02 09:18:04 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	char const	*tmp;
	size_t		len_cpy;

	if (!s)
		return (0);
	tmp = s;
	len_cpy = len;
	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	while (*tmp && len_cpy)
	{
		tmp++;
		len_cpy--;
	}
	len = tmp - s;
	sub = ft_calloc(len + 1, sizeof(char));
	if (sub == 0)
		return (0);
	return (ft_memcpy(sub, s + start, len));
}
