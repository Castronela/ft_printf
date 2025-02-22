/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:44:03 by dstinghe          #+#    #+#             */
/*   Updated: 2025/02/22 22:19:41 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERR_C_MALLOC -1

# define F_ALIGN_L 0x01  			// align left
# define F_PAD_ZERO 0x02 			// pad with zero
# define F_ALT_FORM 0x04 			// use alternate form
# define F_SIGN 0x08     			// use + sign
# define F_SIGN_SP 0x10  			// use space as placeholder for sign

# define FORMAT_FLAGS "-0# +"     	// recognized printf flags
# define FORMAT_TYPES "cspdiuxX%" 	// recognized printf conversion specifiers

# define BASE_10 "0123456789"
# define BASE_16_LOWER "0123456789abcdefg"
# define BASE_16_UPPER "0123456789ABCDEFG"

typedef struct s_string
{
	const char		*raw_string;
	size_t			len;

	char			format_type;
	char			format_flag;

	int				size_pad_before;
	char			sign;
	char			*alt;
	int				size_pad_zero;
	int				accuracy_size;
	char			*format_string;
	char			format_char;
	int				size_pad_after;

	struct s_string	*next;
}					t_string;

typedef struct s_printf
{
	va_list			args;
	t_string		*strings;
	char			*output;
	int				return_code;
}					t_printf;

/* ========================= Function declarations ========================= */

int					ft_printf(const char *c, ...);

/* --------------------------------- Flags --------------------------------- */

void				init_flags(t_string *string);

/* ------------------------------ String List ------------------------------ */

t_string			*lst_new(t_printf *data, const char *ptr);
void				lst_add_back(t_string **head, t_string *node);
t_string			*lst_last(t_string *lst);
void				lst_free(t_string **head);
void				free_mem(t_printf *data);

/* ----------------------- Conversion and Formating  ----------------------- */

int					init_chars(t_printf *data, t_string *string);
int					init_base_10(t_printf *data, t_string *string);
int					init_base_16(t_printf *data, t_string *string);
int					init_ptr(t_printf *data, t_string *string);

/* ----------------------- Assemble and print output ----------------------- */

int					print_output(t_printf *data);

/* --------------------------------- Utils --------------------------------- */

bool				is_in_set(const char c, const char *set);
bool				is_format_string(const char *str);
char				*itoa(long long num, int base, const char *base_chars,
						char *sign);
void				set_pad_size(t_string *string);

/* ------------------------------ Libft Utils ------------------------------ */

int					my_atoi(const char *str);
char				*my_strdup(const char *s1, int size);
size_t				my_strlen(const char *str);
size_t				my_strlcpy(char *dst, const char *src, int dstsize);

#endif