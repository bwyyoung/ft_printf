/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 19:10:53 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/26 19:41:42 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** I'm aware this is perhaps not the fastest way of handling printf,
** but in my opinion it is the most understandable.
*/

static void			final_padding(t_conversion *conversion
										  , char **string)
{
	char			*new;
	char			*padding;
	intmax_t		needed;

	needed = conversion->width - ft_strlen(*string);
	if (needed > 0)
	{
		padding = ft_strnew(needed);
		ft_memset(padding, ' ', needed);
		if (conversion->flags.left_justify)
			new = ft_strjoin(*string, padding);
		else
			new = ft_strjoin(padding, *string);
		free(*string);
		free(padding);
		*string = new;
	}
}

static t_get_string	get_string_getter(t_specifier specifier)
{
	if (specifier == STRING)
		return (get_string_string);
	else if (specifier == POINTER)
		return (get_string_pointer);
	else if (specifier == OCTAL)
		return (get_string_octal);
	else if (specifier == HEX_UPPER || specifier == HEX_LOWER)
		return (get_string_hex);
	else if (specifier == CHAR)
		return (get_string_char);
	return (get_string_decimal);
}

static size_t		written_particulars(t_conversion *conversion, char *string)
{
	if (conversion->specifier == CHAR && string[0] == '\0')
		return (1);
	return (0);
}

void				print_normal(t_conversion *conversion
								 , va_list arguments
								 , size_t *written)
{
	char			*string;
	t_get_string	getter;

	getter = get_string_getter(conversion->specifier);
	string = getter(conversion, arguments);
	final_padding(conversion, &string);
	ft_putstr(string);
	*written += ft_strlen(string) + written_particulars(conversion, string);
	free(string);
}
