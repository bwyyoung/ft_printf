/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 23:03:06 by tfleming          #+#    #+#             */
/*   Updated: 2014/12/30 22:54:52 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_normal_conversion(t_conversion *conversion
											, va_list arguments
											, size_t *written)
{
	if (conversion->specifier == S_DECIMAL)
		print_signed_decimal(conversion, arguments, written);
}

static void			print_special_string(t_conversion *conversion
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
		print_special_string(conversion, arguments, written);
	else
		print_normal_conversion(conversion, arguments, written);
}
