/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 16:09:41 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/13 16:39:09 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// don't foget to delete this

#include "libft.h"
#include <stdio.h>

int					main(void)
{
	printf("ft_itoa_large(((long)INT_MAX) + 1) = %s\n"
		   , ft_itoa_large(((long)INT_MAX) + 1));
	printf("ft_itoa_large(((long)INT_MAX) + 1) = %ld\n", ((long)INT_MAX) + 1);
	
	/* int				sup; */
	/* long			value; */

	/* (void)sup; */
	/* value = (long)&sup; */
	/* printf("mine  : %s\n", ft_basetoa(value, 16)); */
	/* printf("theirs: %lX\n", value); */
	return (0);
}
