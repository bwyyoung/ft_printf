/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned_decimal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 11:14:05 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/09 11:16:02 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	handle_unsigned_decimal(va_list arguments
									 , t_conversion conversion)
{
	if (length == HH)
		return (va_arg(arguments, unsigned int));
	if (length == H)
		return (va_arg(arguments, unsigned int));
	if (length == L)
		return (va_arg(arguments, unsigned long));
	if (length == LL)
		return (va_arg(arguments, unsigned long long));
	if (length == J)
		return (va_arg(arguments, uintmax_t));
	if (length == Z)
		return (va_arg(arguments, size_t));
	return (va_arg(arguments, int));
}
