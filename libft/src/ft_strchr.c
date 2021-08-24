/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:31:47 by rballage          #+#    #+#             */
/*   Updated: 2019/12/12 19:31:48 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (s)
		while (*s)
		{
			if (*s == (char)c)
				return ((char*)s);
			s++;
		}
	if (*s == '\0' && c == '\0')
		return ((char*)s);
	return (NULL);
}
