/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_sharp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:58:04 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 17:58:07 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_sharp_hexa(t_plist *list, long double nb, int i, char *str)
{
	if (list->sharp == 1 && list->mode > 0 && list->mode < 3 && !list->minus
	&& !list->zero && !list->sharp_placed && nb != 0)
	{
		str[i++] = '0';
		str[i++] = ((list->mode == HEXA_LOW) ? 'x' : 'X');
	}
	else if (!list->minus && !list->zero && !list->sharp_placed
	&& list->pointer)
	{
		str[i++] = '0';
		str[i++] = 'x';
	}
	return (i);
}

int	check_sharp_hexa_minus(t_plist *list, long double nb, int i, char *str)
{
	if (list->sharp == 1 && list->mode > 0 && list->mode < 3
		&& (list->minus || list->zero) && nb != 0)
	{
		str[i++] = '0';
		str[i++] = ((list->mode == HEXA_LOW) ? 'x' : 'X');
		list->sharp_placed = 1;
	}
	else if (list->minus && list->pointer)
	{
		str[i++] = '0';
		str[i++] = 'x';
		list->sharp_placed = 1;
	}
	return (i);
}

int	check_sharp_hexa_field(t_plist *list, long double nb, int i, char *str)
{
	if (list->sharp == 1 && list->mode > 0 && list->mode < 3
		&& !list->minus && !list->sharp_placed && nb != 0)
	{
		str[i++] = '0';
		str[i++] = ((list->mode == HEXA_LOW) ? 'x' : 'X');
		list->sharp_placed = 1;
	}
	else if (!list->minus && list->pointer && !list->sharp_placed)
	{
		str[i++] = '0';
		str[i++] = 'x';
		list->sharp_placed = 1;
	}
	return (i);
}

int	check_sharp_octal(t_plist *list, long double nb, int i, char *str)
{
	if (list->sharp == 1 && list->mode == OCTAL && nb > 0
		&& list->prec <= list->nb_l)
		str[i++] = '0';
	else if (list->sharp == 1 && list->mode == OCTAL && nb == 0
		&& list->dot && list->prec == 0)
		str[i++] = '0';
	return (i);
}
