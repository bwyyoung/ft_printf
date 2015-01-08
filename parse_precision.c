/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 19:15:59 by tfleming          #+#    #+#             */
/*   Updated: 2014/12/28 18:20:42 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** very much like parse_width
*/

void				precision_too_big(t_format *format)
{
	ft_putstr_fd("ft_printf: precision argument too large (int max = ", 2);
	ft_putnbr_fd(INT_MAX, 2);
	ft_putstr_fd(")\n", 2);
	print_format_error(format);
	exit(1);
}

void				parse_precision(t_conversion *conversion, t_format *format)
{
	size_t			i;
	char			current;

	conversion->precision = 0;
	i = 0;
	while (((current = *(get_current(format) + i))) && ft_isdigit(current))
	{
		ft_atoi_add_digit(current, &conversion->precision);
		if (conversion->precision < 0)
			precision_too_big(format);
		i++;
	}
	format->location += i;
}
