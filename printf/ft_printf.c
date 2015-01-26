/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 16:36:21 by tfleming          #+#    #+#             */
/*   Updated: 2014/12/26 22:27:19 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *format_string, ...)
{
	va_list			arguments;
	t_format		format;

	if (!format_string)
	{
		ft_putendl_fd("ft_printf: format string must be valid", 2);
		exit(1);
	}
	format.string = format_string;
	format.location = 0;
	format.written = 0;
	va_start(arguments, format_string);
	handle_format(&format, arguments);
	va_end(arguments);
	return (format.written);
}
