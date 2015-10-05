/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 14:25:03 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/09 14:25:08 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	char	*s3;

	s3 = s1;
	while ((*s3 = *s2))
	{
		if (*s2 == '\0')
			break ;
		s2++;
		s3++;
	}
	*s3 = '\0';
	return (s1);
}
