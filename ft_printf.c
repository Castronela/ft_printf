/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstinghe <dstinghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:54:42 by dstinghe          #+#    #+#             */
/*   Updated: 2024/03/25 17:32:22 by dstinghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *c, ...)
{
	va_list	args;
	int		return_code;

	va_start(args, c);
	return_code = 0;
	while (*c)
	{
		if (*c == '%')
		{
			if (check_conversion(++c, args, &return_code) < 0)
				return (-1);
		}
		else if (my_putchar(*c, &return_code) < 0)
			return (-1);
		c++;
	}
	va_end(args);
	return (return_code);
}
