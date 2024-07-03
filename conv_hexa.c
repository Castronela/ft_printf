/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstinghe <dstinghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:22:31 by dstinghe          #+#    #+#             */
/*   Updated: 2024/03/25 17:34:18 by dstinghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(unsigned long address, int char_case, int *return_code)
{
	char	c;

	if (address < 16)
	{
		if (char_case == 0)
			c = "0123456789abcdef"[address % 16];
		else
			c = "0123456789ABCDEF"[address % 16];
		if (my_putchar(c, return_code) < 0)
			return (-1);
	}
	else
	{
		if (ft_putaddress(address / 16, char_case, return_code) < 0)
			return (-1);
		if (char_case == 0)
			c = "0123456789abcdef"[address % 16];
		else
			c = "0123456789ABCDEF"[address % 16];
		if (my_putchar(c, return_code) < 0)
			return (-1);
	}
	return (1);
}
