/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:59:27 by david             #+#    #+#             */
/*   Updated: 2025/02/22 01:46:19 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_format_flags(t_string *string, size_t *index);

void	init_flags(t_string *string)
{
	size_t	index;

	index = 1;
	init_format_flags(string, &index);
	if (string->format_flag & F_ALIGN_L)
		string->size_pad_after = my_atoi(&string->raw_string[index]);
	else if (string->format_flag & F_PAD_ZERO && !is_in_set(string->format_type,
			"cs") && !(string->format_flag & F_ALIGN_L))
		string->size_pad_zero = my_atoi(&string->raw_string[index]);
	else
		string->size_pad_before = my_atoi(&string->raw_string[index]);
	while (index < string->len && string->raw_string[index] != '.')
		index++;
	if (string->raw_string[index++] == '.')
	{
		string->accuracy_size = my_atoi(&string->raw_string[index]);
		string->size_pad_zero = -1;
	}
}

static void	init_format_flags(t_string *string, size_t *index)
{
	while (*index < string->len)
	{
		if (string->raw_string[*index] == '-')
			string->format_flag |= F_ALIGN_L;
		else if (string->raw_string[*index] == '0')
			string->format_flag |= F_PAD_ZERO;
		else if (string->raw_string[*index] == '#')
			string->format_flag |= F_ALT_FORM;
		else if (string->raw_string[*index] == ' ')
			string->format_flag |= F_SIGN_SP;
		else if (string->raw_string[*index] == '+')
			string->format_flag |= F_SIGN;
		else
			break ;
		(*index)++;
	}
}
