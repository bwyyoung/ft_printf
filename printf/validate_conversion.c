/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:58:37 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/28 18:17:36 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*get_length_string(t_length length)
{
	if (length == HH)
		return (ft_strdup("hh"));
	if (length == H)
		return (ft_strdup("hh"));
	if (length == L)
		return (ft_strdup("l"));
	if (length == LL)
		return (ft_strdup("ll"));
	if (length == J)
		return (ft_strdup("j"));
	if (length == Z)
		return (ft_strdup("z"));
	return (ft_strdup("DEFAULT"));
}

static int			pointer_has_specified_size(t_conversion *conversion
											   , t_format *format)
{
	char			*length;
	
	if (conversion->specifier == POINTER)
	{
		if (conversion->length != DEFAULT_LENGTH)
		{
			length = get_length_string(conversion->length);
			ft_putstr_fd("ft_printf: length modifier '", 2);
			ft_putstr_fd(length, 2);
			ft_putstr_fd("' results in undefined behavior or no effect ", 2);
			ft_putendl_fd("with 'p' conversion specifier", 2);
			print_format_error(format);
			return (ERROR);
		}
	}
	return (OKAY);
}

static int			is_it_okay(t_conversion *conversion
										, t_format *format)
{
	if (pointer_has_specified_size(conversion, format) == OKAY
		&& validate_flags(conversion, format) == OKAY)
		return (OKAY);
	return (ERROR);
}

int					validate_conversion(t_conversion *conversion
										, t_format *format)
{
	int				returned;

	format->location--;
	returned = is_it_okay(conversion, format);
	format->location++;
	return (returned);
}
