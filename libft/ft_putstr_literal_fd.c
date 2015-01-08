// header

#include "libft.h"

static void			print_literal(char c)
{
	if (c == '\n')
		ft_putstr("\\n");
	if (c == '\t')
		ft_putstr("\\t");
}

void				ft_putstr_literal_fd(char const *source)
{
	while (*source)
	{
		print_literal(*source);
		source++;
	}
}
