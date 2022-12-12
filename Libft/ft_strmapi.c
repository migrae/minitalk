/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:36:16 by mgraefen          #+#    #+#             */
/*   Updated: 2022/11/01 10:51:36 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	len;
	int				i;

	if (!s || !(*f))
		return (0);
	i = 0;
	len = ft_strlen(s);
	out = ft_calloc(len + 1, sizeof(char));
	if (!out)
		return (0);
	while (len)
	{
		out[i] = (*f)(i, s[i]);
		i++;
		len--;
	}
	out[i] = '\0';
	if (!out)
		return (0);
	return (out);
}
