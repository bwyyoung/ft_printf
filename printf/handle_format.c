/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 21:00:03 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/26 20:12:06 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int			check_percent_percent(t_format *format)
{
	if (*get_current(format) == '%')
	{
		ft_putchar('%');
		format->location++;
		format->written++;
		return (1);
	}
	else
		return (0);
}

static void			handle_conversion(t_format *format, va_list arguments)
{
	t_conversion	conversion;

	if (check_percent_percent(format))
		return ;
	ft_bzero(&conversion, sizeof(conversion));
	if (parse_conversion(&conversion, arguments, format) == OKAY
		&& validate_conversion(&conversion, format) == OKAY)
		should_not_print = print_conversion(&conversion, arguments
											, &format->written);
	else if (*get_current(format) == '%')
	{
		ft_putchar('%');
		format->location++;
		format->written++;
	}
}

void				handle_format(t_format *format, va_list arguments)
{
	char			current;
	t_bool			should_not_print;

	should_not_print = 0;
	while ((current = *get_current(format)))
	{
		if (current == '%')
		{
			format->location++;
			handle_conversion(format, arguments, &should_not_print);
		}
		else
		{
			ft_putchar(current);
			format->written++;
			format->location++;
		}
	}
}
