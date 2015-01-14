/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:49:28 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/13 14:00:42 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*get_string_string(t_conversion *conversion
									   , va_list arguments)
{
	char			*string;

	if (!(string = va_arg(arguments, char*)))
		return (ft_strdup("(null)"));
	string = ft_strdup(string);
	(void)conversion;
	return (string);
}
