// header

#include "libft.h"

/*
** adds a single digit to a number;  be used in atoi implementations
*/

void				ft_atoi_add_digit(const char c, int *number)
{
	if (*number)
		*number *= 10;
	*number += c - '0';
}
