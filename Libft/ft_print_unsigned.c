/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:55:45 by mgraefen          #+#    #+#             */
/*   Updated: 2022/12/08 11:13:51 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsigned_len(unsigned int n)
{
	int				len;

	len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_put_unsigned(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_unsigned_len(n);
	str = (char *) ft_calloc(sizeof(char *), len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	while (n)
	{
		str[len - 1] = n % 10 + '0';
		len --;
		n = n / 10;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*str;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		str = ft_put_unsigned(n);
		len += ft_print_str(str);
		free(str);
	}
	return (len);
}
