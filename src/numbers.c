/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:52:53 by david             #+#    #+#             */
/*   Updated: 2025/02/22 19:46:23 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			init_base_10(t_printf *data, t_string *string);
int			init_base_16(t_printf *data, t_string *string);
int			init_ptr(t_printf *data, t_string *string);

static void	set_signage(t_string *string);
static int	set_alt(t_string *string);

int	init_base_10(t_printf *data, t_string *string)
{
	long int	num;

	if (string->format_type == 'u')
		num = va_arg(data->args, unsigned int);
	else
		num = va_arg(data->args, int);
	if (num != 0 || string->accuracy_size != 0)
	{
		string->format_string = itoa(num, 10, BASE_10, &string->sign);
		if (!string->format_string)
			return (1);
	}
	set_signage(string);
	return (0);
}

int	init_base_16(t_printf *data, t_string *string)
{
	unsigned int	num;

	num = va_arg(data->args, unsigned int);
	if (num != 0 || string->accuracy_size != 0)
	{
		if (string->format_type == 'x')
			string->format_string = itoa(num, 16, BASE_16_LOWER, &string->sign);
		else
			string->format_string = itoa(num, 16, BASE_16_UPPER, &string->sign);
		if (!string->format_string)
			return (1);
	}
	if (num != 0)
	{
		if (set_alt(string))
			return (1);
	}
	return (0);
}

int	init_ptr(t_printf *data, t_string *string)
{
	unsigned long	ptr;

	ptr = va_arg(data->args, unsigned long);
	if (ptr == 0)
		string->format_string = my_strdup("(nil)", 5);
	else
		string->format_string = itoa(ptr, 16, BASE_16_LOWER, &string->sign);
	if (!string->format_string)
		return (1);
	if (ptr == 0)
	{
		string->accuracy_size = -1;
		string->size_pad_zero = 0;
		return (0);
	}
	set_signage(string);
	if (set_alt(string))
		return (1);
	return (0);
}

static void	set_signage(t_string *string)
{
	if (string->format_flag & F_SIGN && !string->sign)
		string->sign = '+';
	else if (string->format_flag & F_SIGN_SP && !string->sign)
		string->sign = ' ';
}

static int	set_alt(t_string *string)
{
	if (string->format_type != 'p' && !(string->format_flag & F_ALT_FORM))
		return (0);
	if (string->format_type == 'X')
		string->alt = my_strdup("0X", 2);
	else
		string->alt = my_strdup("0x", 2);
	if (!string->alt)
		return (1);
	return (0);
}
