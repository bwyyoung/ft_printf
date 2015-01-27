/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:11:57 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/27 14:45:37 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int					main(void)
{
	int				printf_ret;
	int				ft_printf_ret;

	printf_ret = printf("theirs 0: |%3c|\n", '\0');
	ft_printf_ret = ft_printf("mine   0: |%3c|\n", '\0');

	printf("printf_ret =\t%d\nfprintf_ret =\t%d\n", printf_ret, ft_printf_ret);
	ft_printf("%4.-5d\n", 7);
	return (0);
}
