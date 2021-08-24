/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:32:46 by rballage          #+#    #+#             */
/*   Updated: 2020/01/10 12:30:53 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) == *(s2 + i) && i < n && *(s1 + i))
		i++;
	if (i != n)
		return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
	return (0);
}
