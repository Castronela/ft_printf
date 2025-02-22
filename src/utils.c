/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:47:47 by david             #+#    #+#             */
/*   Updated: 2025/02/22 16:27:49 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool			is_format_string(const char *str);
bool			is_in_set(const char c, const char *set);
char			*itoa(long long num, int base, const char *base_chars,
					char *sign);
void			set_pad_size(t_string *string);

static size_t	numlen(unsigned long long num, int base);

bool	is_format_string(const char *str)
{
	size_t	dot_count;

	if (*str != '%')
		return (false);
	str++;
	while (is_in_set(*str, FORMAT_FLAGS))
		str++;
	dot_count = 0;
	while (*str)
	{
		if (dot_count > 1)
			return (false);
		if (is_in_set(*str, FORMAT_TYPES))
			return (true);
		if (*str == '.')
			dot_count++;
		else if (!is_in_set(*str, BASE_10))
			return (false);
		str++;
	}
	return (false);
}

bool	is_in_set(const char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (true);
		set++;
	}
	return (false);
}

char	*itoa(long long num, int base, const char *base_chars, char *sign)
{
	unsigned long long	nb;
	size_t				is_neg;
	char				*str;
	size_t				num_len;

	is_neg = (num < 0 && base == 10);
	nb = num;
	if (is_neg)
	{
		nb = -num;
		*sign = '-';
	}
	num_len = numlen(nb, base);
	str = malloc(sizeof(*str) * (num_len + 1));
	if (!str)
		return (NULL);
	str[num_len] = 0;
	while (num_len > 0)
	{
		str[--num_len] = base_chars[nb % base];
		nb /= base;
	}
	return (str);
}

static size_t	numlen(unsigned long long num, int base)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= base;
		len++;
	}
	return (len);
}

void	set_pad_size(t_string *string)
{
	size_t	str_len;

	str_len = 1;
	if (string->format_string)
		str_len = my_strlen(string->format_string);
	if (string->accuracy_size > (int)str_len)
	{
		string->accuracy_size -= str_len;
		str_len += string->accuracy_size;
	}
	else
		string->accuracy_size = 0;
	str_len += (string->sign > 0) + my_strlen(string->alt);
	if (string->size_pad_before > (int)str_len)
		string->size_pad_before -= str_len;
	else
		string->size_pad_before = 0;
	if (string->size_pad_zero > (int)str_len)
		string->size_pad_zero -= str_len;
	else
		string->size_pad_zero = 0;
	if (string->size_pad_after > (int)str_len)
		string->size_pad_after -= str_len;
	else
		string->size_pad_after = 0;
}
