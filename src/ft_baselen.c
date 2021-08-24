/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_baselen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:59:41 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 17:59:56 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_baselen(unsigned long long nb, unsigned long long base)
{
	int i;

	i = 1;
	while (nb > base - 1)
	{
		nb /= base;
		i++;
	}
	return (i);
}
