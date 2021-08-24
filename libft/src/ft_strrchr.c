/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:33:51 by rballage          #+#    #+#             */
/*   Updated: 2020/01/10 12:30:39 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*t;

	t = (0);
	while (*s)
	{
		if (*(s) == c)
			t = (char*)s;
		++s;
	}
	if (t)
		return (t);
	if (c == '\0')
		return ((char *)s);
	return (t);
}
