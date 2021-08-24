/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:31:03 by rballage          #+#    #+#             */
/*   Updated: 2018/11/18 10:31:04 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_prime(int nb)
{
	int sq;

	sq = 3;
	if (nb == 2)
		return (1);
	if (nb <= 1)
		return (0);
	if (nb == 4 || nb % 2 == 0)
		return (0);
	while (sq < nb / 2)
	{
		if ((nb / sq) * sq == nb)
			return (0);
		else
			sq = sq + 2;
	}
	return (1);
}
