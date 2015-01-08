// header

#include "libft.h"

size_t				ft_strcount(char const *haystack, char const needle)
{
	size_t			count;
	
	while (haystack)
	{
		if (*haystack == needle)
			count++;
		haystack++;
	}
	return (count);
}
