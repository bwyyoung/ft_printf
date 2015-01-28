/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:11:57 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/28 21:32:34 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int					main(void)
{
	int				printf_ret;
	int				ft_printf_ret;

	ft_printf_ret = ft_printf("|%4.1s|\n", "42");
	printf_ret = printf("|%4.1s|\n", "42");

	printf("ft_printf_ret =\t%d\nprintf_ret =\t%d\n"
				, ft_printf_ret, printf_ret);

	/* printf("%03.2d", 0); */
	/* printf("%03.2u", 0); */
	/* printf("%03.2o", 0); */
	/* printf("%03.2x", 0); */
	/* printf("%03.2X", 0); */
	/* printf("%03.2c", 0); */
	/* printf("%03.2s", NULL); */
	/* printf("%03.2p", NULL); */
	return (0);
}
