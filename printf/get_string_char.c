/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:01:12 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/26 19:49:28 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*get_string_char(t_conversion *conversion
									, va_list arguments)
{
	char			*string;

	string = ft_strnew(1);
	string[0] = (char)va_arg(arguments, int);
	return (string);
}
