/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:34:26 by rballage          #+#    #+#             */
/*   Updated: 2018/11/18 10:34:27 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int i;
	int j;

	i = -1;
	j = (int)ft_strlen(dest);
	while (*(src + ++i) && i < (int)n)
		*(dest + j++) = *(src + i);
	*(dest + j) = '\0';
	return (dest);
}
