// header

#include "libft.h"

void			ft_putnbr_large_fd(intmax_t number, int file_descriptor)
{
	char	*string;

	string = ft_itoa_large(number);
	ft_putstr_fd(string, file_descriptor);
	free(string);
}
