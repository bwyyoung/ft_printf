/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 15:24:16 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/08 15:53:13 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void			break_it_up(void)
{
	ft_putstr("\n\n");
}

int					main(void)
{
	ft_putendl("'0' flag ignored with precision and %d");
	ft_printf("%0.13d", 42);
	break_it_up();

	ft_putendl("use  length modifier with 'O' type character 'O'");


	TEST("%+ d", 42);
	TEST("%hp", NULL);
		/* TEST("%+u", 0); */
	/* TEST("%0c", 0); */
	/* TEST("%0s", "asdf"); */
	/* TEST("%0p", NULL); */
	TEST("%.4c", 'c');
	TEST("%.4p", NULL);
	return (0);
}						 
