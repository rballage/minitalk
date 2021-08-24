/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:54:57 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 17:54:58 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pad_r_zero(t_plist *list, long double nb, int i, char *str)
{
	int j;

	j = nb < 0 ? list->nb_l - 1 : list->nb_l;
	if (list->dot == 1 && list->prec > j && list->type == nbr)
	{
		if (nb < 0)
		{
			str[i++] = '-';
			list->res++;
		}
		while (j < list->prec)
		{
			str[i++] = '0';
			j++;
		}
	}
	return (i);
}

int	pad_l_spaces(t_plist *list, int i, char *str)
{
	int j;

	j = list->nb_l;
	if (list->dot == 1 && list->prec < 0)
	{
		while (j < ft_abs(list->prec))
		{
			str[i++] = ' ';
			j++;
		}
	}
	return (i);
}
