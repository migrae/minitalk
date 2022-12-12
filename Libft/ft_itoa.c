/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:22:34 by mgraefen          #+#    #+#             */
/*   Updated: 2022/11/01 11:23:08 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_create_str(int sign, long int len, long int nb)
{
	char		*out;

	out = (char *) ft_calloc((len + 1 + sign), sizeof(char));
	if (!out)
		return (0);
	if (sign == 1)
		out[0] = '-';
	out[len + sign] = '\0';
	if (nb == 0)
		out[len - 1] = 0 + '0';
	while (nb > 0)
	{
		out[len + sign - 1] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	return (out);
}

char	*ft_itoa(int n)
{
	int			sign;
	long int	len;
	long int	nb;

	nb = (long int) n;
	sign = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		sign = 1;
	}
	len = ft_intlen(nb);
	return (ft_create_str(sign, len, nb));
}
