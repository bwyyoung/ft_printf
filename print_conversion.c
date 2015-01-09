/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 23:03:06 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/09 11:24:02 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			string(va_list arguments, t_conversion conversion)
{
	// for a string
}

static void			handle_normal_conversion(t_conversion *conversion
											, va_list arguments
											, size_t *written)
{
	if (conversion->specifier == S_DECIMAL
		|| conversion->specifier == U_DECIMAL)
		handle_decimal(conversion, arguments, written);
	else if (conversion->specifier == OCTAL)
		print_octal(octal(
	
	
}

static void			handle_special_string(t_conversion *conversion
											, va_list arguments
											, size_t *written)
{
	(void)conversion;
	(void)arguments;
	(void)written;
}

void				print_conversion(t_conversion *conversion
									 , va_list arguments
									 , size_t *written)
{
	if (conversion->specifier == STRING
			&& conversion->length > HH)
		handle_special_string(conversion, arguments, written);
	else
		handle_normal_conversion(conversion, arguments, written);
}
