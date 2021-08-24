/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:34:42 by rballage          #+#    #+#             */
/*   Updated: 2018/11/19 10:11:56 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_recrev(char *str, char *str_cp, int i)
{
	if (i == -1)
		return (0);
	else
		str[i] = str_cp[(ft_strlen(str) - 1) - i];
	i--;
	return (ft_recrev(str, str_cp, i));
}

char		*ft_strrev(char *str)
{
	int		i;
	char	str_cp[ft_strlen(str)];

	i = 0;
	while (str[i] != '\0')
	{
		str_cp[i] = str[i];
		i++;
	}
	str_cp[i] = '\0';
	ft_recrev(str, str_cp, i - 1);
	return (str);
}
