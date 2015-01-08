// header

#include "ft_printf.h"

/*
** ft_printf("this is an error %m\n");
**            ~~~~~~~~~~~~~~~~~~^~~
*/

void				print_format_error(t_format *format)
{
	ft_putstr_fd(PROGRAM_NAME, 2);
	ft_putstr_fd("(\"", 2);
	ft_putstr_fd(format->string, 2);
	ft_putstr_fd("\")\n", 2);
	ft_putcharn_fd(' ', ft_strlen(PROGRAM_NAME) + 2, 2);
	ft_putcharn_fd('~', format->location, 2);
	ft_putchar_fd('^', 2);
	ft_putcharn_fd('~', ft_strlen(format->string) - format->location - 1, 2);
	ft_putchar_fd('\n', 2);
}
