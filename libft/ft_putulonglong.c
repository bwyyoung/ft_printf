/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulonglong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 16:18:22 by tfleming          #+#    #+#             */
/*   Updated: 2014/12/19 16:30:11 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putulonglong(unsigned long long number)
{
	if (number > 9)
		ft_putulonglong(number / 10);
	ft_putchar(number % 10 + '0');
}
