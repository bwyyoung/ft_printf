// header

#include "ft_printf.h"

char				*get_string_octal(t_conversion *conversion
									  , va_list arguments)
{
	char			*string;
	uintmax_t		value;

	value = get_unsigned_number_argument(conversion->length, arguments);
	string = ft_basetoa(value, 8);
	return (string);
}
