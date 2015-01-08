/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 16:36:32 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/08 15:23:47 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** stdarg: unknown number of arguments
** wchar: wide characters
** limits: upper and lower values of primitive types
*/

# include "libft/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>

# define PROGRAM_NAME					"ft_printf"

typedef char			t_bool;

typedef struct			s_format
{
	const char	*string;
	size_t		location;
	size_t		written;
}						t_format;

typedef struct			s_flags
{
	t_bool		left_justify;
	t_bool		pad_with_zeros;
	t_bool		show_sign;
	t_bool		positive_values_begin_blank;
	t_bool		number_sign;
}						t_flags;

/*
** sorted by size (generally speaking)
** DEFAULT_LENGTH because bzero at beginning has to make new conversion
*/

typedef enum			e_length
{
	DEFAULT_LENGTH, HH, H, L, LL, J, Z
}						t_length;

/*
** see parse_specifier for longer list of specifiers
*/

typedef enum			e_specifier
{
	S_DECIMAL, U_DECIMAL, OCTAL, HEX_LOWER, HEX_UPPER, CHAR, STRING, POINTER
	, INVALID_SPECIFIER
}						t_specifier;

/*
** precision = 0+: '.' with or without number after it (default -1)
*/

typedef struct			s_conversion
{
	t_flags		flags;
	int			width;
	int			precision;
	t_length	length;
	t_specifier	specifier;
}						t_conversion;

int						ft_printf(const char *format_string, ...);
void					handle_format(t_format *format, va_list arguments);
void					parse_conversion(t_conversion *conversion
										 , t_format *format);
void					parse_flags(t_conversion *conversion, t_format *format);
void					parse_width(t_conversion *conversion, t_format *format);
void					parse_precision(t_conversion *conversion
										, t_format *format);
void					parse_length(t_conversion *conversion
									 , t_format *format);
void					parse_specifier(t_conversion *conversion
										, t_format *format);
void					print_conversion(t_conversion *conversion
										 , va_list arguments
										 , size_t *written);
void					print_signed_decimal(t_conversion *conversion
											 , va_list arguments
											 , size_t *written);
void					print_format_error(t_format *format);
const char				*get_current(t_format *format);

#endif
