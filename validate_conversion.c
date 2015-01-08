/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:58:37 by tfleming          #+#    #+#             */
/*   Updated: 2014/12/30 23:18:22 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				validate_zero_flag(t_conversion *conversion)
{
	/*	if (conversion->specifier < CHAR)
	{
		conversion->precision = conversion->width;
		conversoin->width = 0;
		}*/
}
	
void				validate_conversion(t_conversion *conversion)
{
	if (conversion->flags.pad_with_zeros)
		validate_zero_flag(conversion);
		
	(void)conversion;
	// flags don't conflict
	// flags can be used with specifier
}
