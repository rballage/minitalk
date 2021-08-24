/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:30:06 by rballage          #+#    #+#             */
/*   Updated: 2020/01/10 12:26:18 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1b;
	unsigned char	*s2b;

	if (n == 0)
		return (0);
	s1b = (unsigned char*)s1;
	s2b = (unsigned char*)s2;
	i = 0;
	while (*s1b == *s2b && ++i < n)
	{
		s1b++;
		s2b++;
	}
	return (*s1b - *s2b);
}
