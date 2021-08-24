/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 11:17:40 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 22:29:02 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static void		putnb(long i, unsigned long long l, char *str)
{
	int		j;

	j = l % 10;
	while (l > 9)
	{
		str[i] = '0' + j;
		l /= 10;
		j = l % 10;
		i--;
	}
	if (i == 0)
		str[0] = '0' + j;
	else
		str[i] = '0' + j;
}

char			*ft_llitoa(long long n)
{
	char						*str;
	unsigned long long			l;
	long						i;
	unsigned long long			origin;

	l = n < 0 ? n * -1 : n;
	i = n < 0 ? 1 : 0;
	origin = l;
	while (l > 9)
	{
		l /= 10;
		i++;
	}
	i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	if (n < 0)
		str[0] = '-';
	putnb(i - 1, origin, str);
	return (str);
}
