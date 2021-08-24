/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:29:55 by rballage          #+#    #+#             */
/*   Updated: 2020/01/10 12:26:10 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s2;
	unsigned char		g;
	size_t				i;

	i = 0;
	s2 = s;
	g = c;
	while (++i <= n && n != 0)
	{
		if (*s2 == g)
			return ((void*)s2);
		s2++;
	}
	return (NULL);
}
