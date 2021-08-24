/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:30:34 by rballage          #+#    #+#             */
/*   Updated: 2020/01/10 12:26:23 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	i = -1;
	if (s1 > s2)
	{
		while (n--)
			s1[n] = s2[n];
	}
	else
		while (s2 && ++i < n)
			s1[i] = s2[i];
	return (dst);
}
