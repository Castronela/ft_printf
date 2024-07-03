/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstinghe <dstinghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:21:11 by dstinghe          #+#    #+#             */
/*   Updated: 2024/03/25 17:35:10 by dstinghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_conversion(const char *c, va_list args, int *return_code)
{
	if (*c == 'c')
		return (my_putchar(va_arg(args, int), return_code));
	else if (*c == 's')
		return (my_putstr(va_arg(args, char *), return_code));
	else if (*c == 'p')
	{
		if (my_putstr("0x", return_code) < 0)
			return (-1);
		return (ft_putaddress(va_arg(args, unsigned long), 0, return_code));
	}
	else if (*c == 'd')
		return (my_itoa(va_arg(args, int), return_code));
	else if (*c == 'i')
		return (my_itoa(va_arg(args, int), return_code));
	else if (*c == 'u')
		return (uns_int(va_arg(args, int), return_code));
	else if (*c == 'x')
		return (ft_putaddress(va_arg(args, unsigned int), 0, return_code));
	else if (*c == 'X')
		return (ft_putaddress(va_arg(args, unsigned int), 1, return_code));
	else if (*c == '%')
		return (my_putchar(37, return_code));
	else
		return (my_putchar(*c, return_code));
}
