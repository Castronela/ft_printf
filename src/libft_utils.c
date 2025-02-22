/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:19:45 by david             #+#    #+#             */
/*   Updated: 2025/02/22 21:10:36 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		my_atoi(const char *str);
char	*my_strdup(const char *s1, int size);
size_t	my_strlen(const char *str);
size_t	my_strlcpy(char *dst, const char *src, int dstsize);

int	my_atoi(const char *str)
{
	int	num;
	int	sign;

	while ((*str > 8 && *str < 14) || *str == ' ')
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
	}
	num = 0;
	while (is_in_set(*str, BASE_10))
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (num * sign);
}

char	*my_strdup(const char *s1, int size)
{
	char	*duplicate;

	if (!s1)
		return (NULL);
	if (size < 0)
		size = my_strlen(s1);
	duplicate = malloc(sizeof(*duplicate) * (size + 1));
	if (!duplicate)
		return (NULL);
	my_strlcpy(duplicate, s1, size);
	duplicate[size] = 0;
	return (duplicate);
}

size_t	my_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		len++;
	return (len);
}

size_t	my_strlcpy(char *dst, const char *src, int dstsize)
{
	int	i;

	if (!dst || !dstsize)
		return (0);
	if (dstsize < 0)
		dstsize = my_strlen(src);
	i = -1;
	while (++i < dstsize)
		dst[i] = src[i];
	return (dstsize);
}
