// header

#include "ft_printf.h"

const char			*get_current(t_format *format)
{
	return (format->string + format->location);
}
