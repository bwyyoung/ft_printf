/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 23:03:06 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/13 14:13:28 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** I'm aware this is perhaps not the fastest way of handling printf,
** but in my opinion it is the most understandable.
*/

static t_get_string	get_string_getter(t_specifier specifier)
{
	if (specifier == S_DECIMAL || specifier == U_DECIMAL)
		return (get_string_decimal);
	else if (specifier == STRING)
		return (get_string_string);
	else if (specifier == POINTER)
		return (get_string_pointer);
	else if (specifier == OCTAL)
		return (get_string_octal);
	else if (specifier == HEX_UPPER || specifier == HEX_LOWER)
		return (get_string_hex);
	return (NULL);
}

static void			print_normal(t_conversion *conversion
								 , va_list arguments
								 , size_t *written)
{
	char			*string;
	t_get_string	getter;

	getter = get_string_getter(conversion->specifier);
	if (getter) // not necessary
		string = getter(conversion, arguments);
	else
		string = ft_strdup("[NOT_HANDLED_YET]");
	ft_putstr(string);
	*written += ft_strlen(string);
	free(string);
}

static void			print_wide(t_conversion *conversion
									   , va_list arguments
									   , size_t *written)
{
	ft_putstr("[WIDE_STRING_OR_CHAR]");
	(void)conversion;
	(void)arguments;
	(void)written;
}

void				print_conversion(t_conversion *conversion
											, va_list arguments
											, size_t *written)
{
	if ((conversion->specifier == STRING || conversion->specifier == CHAR)
		&& conversion->length >= L)
		print_wide(conversion, arguments, written);
	else
		print_normal(conversion, arguments, written);
}
