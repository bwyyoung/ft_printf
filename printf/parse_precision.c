/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 19:15:59 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 15:35:03 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** very much like parse_width
*/

static int			precision_too_long(t_conversion *conversion
											, t_format *format)
{
	ft_putstr_fd("ft_printf: suspicious precision given by * argument: ", 2);
	ft_putnbr_large_fd(conversion->precision, 2);
	ft_putstr_fd("\n", 2);
	print_format_error(format);
	return (ERROR);
}

static void			from_star(t_conversion *conversion
								, va_list arguments, t_format *format)
{
	conversion->precision = va_arg(arguments, unsigned int);
	if (conversion->precision > LARGEST_STAR_ARGUMENT)
	{
		precision_too_long(conversion, format);
		conversion->precision = 0;
	}
	format->location += 1;
}

static void			written_numbers(t_conversion *conversion, t_format *format)
{
	size_t			i;
	char			current;

	i = 0;
	while (((current = *(get_current(format) + i)))
			&& ft_isdigit(current))
	{
		ft_atoi_add_digit_u(current, &conversion->precision);
		i++;
	}
	format->location += i;
}

int					parse_precision(t_conversion *conversion
									, va_list arguments, t_format *format)
{
	if (*get_current(format) == '.')
	{
		format->location++;
		if (*get_current(format) == '*')
			from_star(conversion, arguments, format);
		else
			written_numbers(conversion, format);
		conversion->precision_set = 1;
	}
	return (OKAY);
}
