/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:29:55 by rballage          #+#    #+#             */
/*   Updated: 2020/06/03 18:30:05 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strjoinf(char const *s1, char const *s2)
{
	char				*str;
	size_t				len1;
	size_t				len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(str = ft_memalloc(len1 + len2 + 1)))
		return (NULL);
	str[len1 + len2] = '\0';
	ft_memcpy(str, s1, len1);
	ft_memcpy((str + len1), s2, len2);
	ft_memdel((void **)&s1);
	ft_memdel((void **)&s2);
	return (str);
}
