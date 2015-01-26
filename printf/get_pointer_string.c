/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:03:41 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/13 16:08:27 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*get_string_pointer(t_conversion *conversion
									   , va_list arguments)
{
	char			*before;
//	char			*string;
	long			value;

	value = (long)va_arg(arguments, void*);
	if (value == 0)
		return (ft_strdup("0x0"));
	before = ft_basetoa(value, 16);
	return (before);
	/* string = ft_strdup("[WORK_IN_PROGRESS]"); */
	
	(void)conversion;
	(void)arguments;
	/* return (string); */
}
