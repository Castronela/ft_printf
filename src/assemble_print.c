/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:18:57 by david             #+#    #+#             */
/*   Updated: 2025/02/22 22:20:34 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_output(t_printf *data);

static void		assemble_output_str(t_printf *data, t_string *string,
					size_t index);
static size_t	get_output_len(t_printf *data);
static void		add_padding(char *str, const char fill, int amount,
					size_t *index);

int	print_output(t_printf *data)
{
	size_t	total_len;

	total_len = get_output_len(data);
	data->output = malloc(sizeof(*data->output) * (total_len + 1));
	if (!data->output)
	{
		free_mem(data);
		return(1);
	}
	data->output[total_len] = 0;
	assemble_output_str(data, data->strings, 0);
	data->return_code = write(STDOUT_FILENO, data->output, total_len);
	return (0);
}

static void	assemble_output_str(t_printf *data, t_string *string, size_t index)
{
	if (string->format_type == 0)
		index += my_strlcpy(&data->output[index], string->raw_string,
				string->len);
	else
	{
		add_padding(data->output, ' ', string->size_pad_before, &index);
		index += my_strlcpy(&data->output[index], &string->sign,
				(string->sign > 0));
		index += my_strlcpy(&data->output[index], string->alt, -1);
		add_padding(data->output, '0', string->size_pad_zero, &index);
		add_padding(data->output, '0', string->accuracy_size, &index);
		if (string->format_type != 'c')
			index += my_strlcpy(&data->output[index], string->format_string,
					-1);
		else
			index += my_strlcpy(&data->output[index], &string->format_char, 1);
		add_padding(data->output, ' ', string->size_pad_after, &index);
	}
	if (string->next)
		assemble_output_str(data, string->next, index);
}

static size_t	get_output_len(t_printf *data)
{
	t_string	*string;
	size_t		len;

	len = 0;
	string = data->strings;
	while (string)
	{
		if (string->format_type == 0)
			len += string->len;
		else
		{
			len += string->size_pad_before;
			len += (string->sign > 0) + my_strlen(string->alt);
			len += string->size_pad_zero;
			if (string->accuracy_size > -1)
				len += string->accuracy_size;
			if (string->format_string)
				len += my_strlen(string->format_string);
			else
				len += 1;
			len += string->size_pad_after;
		}
		string = string->next;
	}
	return (len);
}

static void	add_padding(char *str, const char fill, int amount, size_t *index)
{
	if (amount < 1)
		return ;
	while (amount--)
		str[(*index)++] = fill;
}
