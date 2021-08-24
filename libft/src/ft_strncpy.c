/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:34:30 by rballage          #+#    #+#             */
/*   Updated: 2018/11/18 10:34:30 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n)
		if (*(src + i) != '\0')
			*(dest + i) = *(src + i);
		else
			while (i < n)
				*(dest + i++) = '\0';
	return (dest);
}
