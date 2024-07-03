/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstinghe <dstinghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:25:40 by dstinghe          #+#    #+#             */
/*   Updated: 2024/03/25 17:35:52 by dstinghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_putchar(char c, int *return_code)
{
	(*return_code)++;
	return (write(1, &c, 1));
}

int	my_putstr(char *s, int *return_code)
{
	if (!s)
		return ((*return_code) += 6, write(1, "(null)", 6));
	while (*s)
	{
		(*return_code)++;
		if (write(1, s++, 1) < 0)
			return (-1);
	}
	return (1);
}
