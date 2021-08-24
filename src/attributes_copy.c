/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:53:51 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 17:53:53 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_if_copy(t_plist *list, long double nb, int i, char *str)
{
	int d;

	d = ft_strlen(list->res);
	if (!(list->dot && !list->prec && !nb && list->type == nbr))
	{
		if (list->type == chr && list->dot && list->prec < d && list->string)
		{
			ft_strncpy(&str[i], list->res, list->prec);
			i += list->prec;
		}
		else
		{
			if (list->zero && nb < 0)
			{
				list->res++;
				d--;
			}
			if (list->type == chr && list->nb_l == 1 && !list->string)
				str[i] = list->data.c;
			else
				ft_strcpy(&str[i], list->res);
			i += (!d && !list->data.c && list->type && list->nb_l == 1) ? 1 : d;
		}
	}
	return (i);
}
