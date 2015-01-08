/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_decimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 18:50:08 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/08 16:32:33 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char			get_prefix(intmax_t value, t_conversion *conversion)
{
	(void)conversion;
	if (value < 0)
		return ('-');
	if (conversion->flags.positive_values_begin_blank)
		return (' ');
	if (conversion->flags.show_sign)
		return ('+');
	return (0);
}

static void			add_left_padding(char **current, int digits, char prefix
									 , t_conversion *conversion)
{
	int				i;

	(void)prefix;
	if (conversion->flags.pad_with_zeros)
	{
		if (conversion->precision == -1)
			return ;
		i = ft_max(conversion->precision + (prefix > 0), digits);
	}
	else
		i = digits;
	while (i < conversion->width)
	{
		**current = ' ';
		(*current)++;
		i++;
	}
}

static void			add_zero_padding(char **current, int digits, char prefix
										 , t_conversion *conversion)
{
	int				i;

	if (conversion->flags.pad_with_zeros && conversion->precision == -1)
		conversion->precision = conversion->width - (prefix > 0);
	i = 0;
	while (i + digits < conversion->precision)
	{
		**current = '0';
		(*current)++;
		i++;
	}
}

static size_t		get_string_length(intmax_t value, int digits, char prefix
									  , t_conversion *conversion)
{
	size_t			length;

	length = 0;
	if (!(value == 0 && conversion->precision != 0))
		length += digits;
	length += conversion->width;
	length += (prefix > 0);
	length += ft_max(conversion->precision - digits, 0);
	return ();
}

static char			*get_string(intmax_t value, t_conversion *conversion)
{
	char			*string;
	char			*current;
	int				digits;
	char			prefix;

	digits = ft_count_digits_umax(ft_abs_max(value));
	prefix = get_prefix(value, conversion);
	string = malloc((get_string_length(value, digits, prefix, conversion) + 1)
					* sizeof(char));
	current = string;
	add_left_padding(&current, digits + (prefix > 0), prefix, conversion);
	if (prefix)
		*(current++) = prefix;
	add_zero_padding(&current, digits, prefix, conversion);
	if (!(value == 0 && conversion->precision == 0))
		ft_itoa_write((current += digits) - 1, ft_abs_max(value));
	*current = '\0';
	return (string);
}

static intmax_t		get_argument(va_list arguments, t_length length)
{
	if (length == HH)
		return (va_arg(arguments, int));
	if (length == H)
		return (va_arg(arguments, int));
	if (length == L)
		return (va_arg(arguments, long));
	if (length == LL)
		return (va_arg(arguments, long long));
	if (length == J)
		return (va_arg(arguments, intmax_t));
	if (length == Z)
		return (va_arg(arguments, size_t));
	return (va_arg(arguments, int));
}

void				print_signed_decimal(t_conversion *conversion
										   , va_list arguments
										   , size_t *written)
{
	char			*string;
	intmax_t		value;

	value = get_argument(arguments, conversion->length);
	string = get_string(value, conversion);
	ft_putstr(string);
	*written += ft_strlen(string);
}
