/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_dec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstinghe <dstinghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:24:28 by dstinghe          #+#    #+#             */
/*   Updated: 2024/03/25 17:34:26 by dstinghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_itoa(long long nb, int *return_code)
{
	char	c;

	if (nb < 0)
	{
		if (nb == -2147483648)
			return (my_putstr("-2147483648", return_code));
		if (my_putchar('-', return_code) < 0)
			return (-1);
		nb = -nb;
	}
	if (nb < 10)
	{
		c = "0123456789"[nb % 10];
		if (my_putchar(c, return_code) < 0)
			return (-1);
	}
	else
	{
		if (my_itoa(nb / 10, return_code) < 0)
			return (-1);
		c = "0123456789"[nb % 10];
		if (my_putchar(c, return_code) < 0)
			return (-1);
	}
	return (1);
}

int	uns_int(int num, int *return_code)
{
	long long	nb;

	if (num < 0)
		nb = (2147483648 * 2) + (long long)num;
	else
		nb = (long long)num;
	return (my_itoa(nb, return_code));
}
