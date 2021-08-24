/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:33:42 by rballage          #+#    #+#             */
/*   Updated: 2020/01/10 12:30:44 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	y;
	int		ct;

	i = len + 1;
	ct = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[0] != '\0' && i-- > 0)
	{
		y = i;
		while (haystack[ct] == needle[ct] && y-- > 0)
		{
			ct++;
			if (needle[ct] == '\0')
				return ((char *)haystack);
		}
		ct = 0;
		haystack++;
	}
	return (0);
}
