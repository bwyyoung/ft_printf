/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 23:03:06 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/26 19:12:54 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				print_wide_string(t_conversion *conversion
										, wchar_t *string
										, size_t *written)
{
	if (string)
		print_wide_chars(conversion, string, ft_strlen_wide(string), written);
	else
	{
		ft_putstr("(null)");
		*written += 6;
	}
}

void				print_wide_char(t_conversion *conversion, wint_t wint
									, size_t *written)
{
	wchar_t	wchar;

	if (wint > 0x10FFFF)
		fprintf(stdout, "INCORRECT!"); // nope
	wchar = (wchar_t)wint;
	print_wide_chars(conversion, &wchar, 1, written);
}

void				print_conversion(t_conversion *conversion
											, va_list arguments
											, size_t *written)
{
	if (conversion->length >= L && conversion->specifier == STRING)
		print_wide_string(conversion, va_arg(arguments, wchar_t*), written);
	else if (conversion->length >= L && conversion->specifier == CHAR)
		print_wide_char(conversion, va_arg(arguments, wchar_t), written);
	else
		print_normal(conversion, arguments, written);
}
