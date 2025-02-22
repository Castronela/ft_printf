/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:54:42 by dstinghe          #+#    #+#             */
/*   Updated: 2025/02/22 22:20:18 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_string_unformated(t_printf *data, const char *c,
				size_t *index);
static int	init_string_formated(t_printf *data, const char *c, size_t *index);
static int	format_sorting(t_printf *data, t_string *string);

int	ft_printf(const char *c, ...)
{
	t_printf	data;
	t_string	*new_string;
	size_t		index;

	data = (t_printf){0};
	va_start(data.args, c);
	index = 0;
	while (c[index])
	{
		new_string = lst_new(&data, &c[index]);
		if (!new_string)
			return (ERR_C_MALLOC);
		lst_add_back(&data.strings, new_string);
		if (is_format_string(&c[index]))
		{
			if (init_string_formated(&data, c, &index))
				return (ERR_C_MALLOC);
		}
		else
			init_string_unformated(&data, c, &index);
	}
	if (print_output(&data))
		return (ERR_C_MALLOC);
	free_mem(&data);
	return (data.return_code);
}

static int	init_string_formated(t_printf *data, const char *c, size_t *index)
{
	t_string	*string;

	string = lst_last(data->strings);
	string->len += 2;
	while (!is_in_set(c[++(*index)], FORMAT_TYPES))
		string->len++;
	string->format_type = c[*index];
	init_flags(string);
	if (format_sorting(data, string))
	{
		free_mem(data);
		return(1);
	}
	set_pad_size(string);
	(*index)++;
	return (0);
}

static void	init_string_unformated(t_printf *data, const char *c, size_t *index)
{
	t_string	*string;

	string = lst_last(data->strings);
	string->format_type = 0;
	string->len++;
	while (c[++(*index)] != '%' && c[*index] != 0)
		string->len++;
}

static int	format_sorting(t_printf *data, t_string *string)
{
	if (is_in_set(string->format_type, "cs%"))
	{
		if (init_chars(data, string))
			return(1);
	}
	else if (is_in_set(string->format_type, "diu"))
	{
		if (init_base_10(data, string))
			return(1);
	}
	else if (is_in_set(string->format_type, "xX"))
	{
		if (init_base_16(data, string))
			return(1);
	}
	else
	{
		if (init_ptr(data, string))
			return(1);
	}
	return (0);
}
