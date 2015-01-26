/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:54:41 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/19 18:15:07 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int					main(void)
{
	printf("output = %d\n", printf("%S", L"asdf\n"));
	printf("output = %d\n", printf("%S", L"米"));
	printf("output = %d\n", printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S"
		   , L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η"
		   , L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ"
		   , L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ"
								   , L"Χ χ", L"Ψ ψ", L"Ω ω", L""));
	printf("ouput = %d\n", printf("long = |%ls|", L"我是一只猫。"));
	return (0);
}
