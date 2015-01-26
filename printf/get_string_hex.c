// header

#include "ft_printf.h"

char				*get_string_hex(t_conversion *conversion
									  , va_list arguments)
{
	char			*string;
	uintmax_t		value;

	value = get_unsigned_number_argument(conversion->length, arguments);
	string = ft_basetoa(value, 16);
	if (conversion->specifier == HEX_LOWER)
		ft_strtolower(string);
	return (string);
}
