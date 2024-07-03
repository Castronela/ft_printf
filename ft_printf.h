/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstinghe <dstinghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:44:03 by dstinghe          #+#    #+#             */
/*   Updated: 2024/03/25 17:32:54 by dstinghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	check_conversion(const char *c, va_list args, int *return_code);
int	my_putchar(char c, int *return_code);
int	my_putstr(char *s, int *return_code);
int	my_itoa(long long nb, int *return_code);
int	uns_int(int num, int *return_code);
int	ft_putaddress(unsigned long address, int char_case, int *return_code);
int	ft_printf(const char *c, ...);

#endif