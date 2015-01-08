/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:38:36 by tfleming          #+#    #+#             */
/*   Updated: 2014/12/28 18:15:35 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** %[flags][width][.precision][length]specifier
*/

void				parse_conversion(t_conversion *conversion, t_format *format)
{
	parse_flags(conversion, format);
	parse_width(conversion, format);
	if (*get_current(format) == '.')
	{
		format->location++;
		parse_precision(conversion, format);
	}
	parse_length(conversion, format);
	parse_specifier(conversion, format);
}
