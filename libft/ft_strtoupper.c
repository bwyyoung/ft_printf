// header

#include "libft.h"

void				ft_strtoupper(char *string)
{
	while (*string)
	{
		*string = ft_toupper(*string);
		string++;
	}
}
