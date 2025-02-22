/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:29:13 by david             #+#    #+#             */
/*   Updated: 2025/02/22 20:00:36 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_str(t_string *string);

int	init_chars(t_printf *data, t_string *string)
{
	char	*str;

	if (string->format_type == 'c')
		string->format_char = va_arg(data->args, int);
	else
	{
		str = "%";
		if (string->format_type == 's')
			str = va_arg(data->args, char *);
		if (!str)
			str = "(null)";
		string->format_string = my_strdup(str, -1);
		if (!string->format_string)
			return (1);
	}
	if (string->format_type == 's' && string->accuracy_size > -1)
		return (format_str(string));
	return (0);
}

static int	format_str(t_string *string)
{
	char	*format;
	int		str_len;

	str_len = my_strlen(string->format_string);
	if (string->accuracy_size > str_len)
		string->accuracy_size = str_len;
	format = malloc(sizeof(*format) * (string->accuracy_size + 1));
	if (!format)
		return (1);
	my_strlcpy(format, string->format_string, string->accuracy_size);
	format[string->accuracy_size] = 0;
	free(string->format_string);
	string->format_string = format;
	string->accuracy_size = -1;
	return (0);
}
