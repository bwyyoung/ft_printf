/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_signed_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 11:25:39 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/09 17:01:17 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t		get_signed_decimal(t_conversion conversion
									   , va_list arguments)
{
	if (length == HH)
		return (va_arg(arguments, int));
	if (length == H)
		return (va_arg(arguments, int));
	if (length == L)
		return (va_arg(arguments, long));
	if (length == LL)
		return (va_arg(arguments, long long));
	if (length == J)
		return (va_arg(arguments, intmax_t));
	if (length == Z) // is this possible?
		return (va_arg(arguments, size_t));
	return (va_arg(arguments, int));
}

char				*get_string_signed_decimal(t_conversion *conversion
											   , va_list arguments
											   , size_t *written)
{
	intmax_t		value;

	value = get_signed_decimal(
}
