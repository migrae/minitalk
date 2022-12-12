/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:21:26 by mgraefen          #+#    #+#             */
/*   Updated: 2022/12/08 11:13:29 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_len(unsigned int dec)
{
	int	len;

	len = 0;
	while (dec)
	{
		dec = dec / 16;
		len++;
	}
	return (len);
}

void	ft_put_hex(unsigned int dec, const char format)
{
	if (dec >= 16)
	{
		ft_put_hex(dec / 16, format);
		ft_put_hex(dec % 16, format);
	}
	else
	{
		if (dec <= 9)
			ft_putchar_fd((dec + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((dec - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((dec - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int dec, const char format)
{
	int	len;

	len = 0;
	if (dec == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(dec, format);
	return (ft_hex_len(dec));
}
