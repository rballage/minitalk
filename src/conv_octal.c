/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:59:19 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 17:59:22 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*convert_octal(unsigned long long nb)
{
	int		i;
	char	*str;

	i = ft_baselen(nb, 8);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	i -= 1;
	while (nb > 7)
	{
		str[i--] = nb % 8 + '0';
		nb /= 8;
	}
	str[i] = nb + '0';
	return (str);
}
