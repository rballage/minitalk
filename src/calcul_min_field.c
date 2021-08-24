/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_min_field.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:54:06 by rballage          #+#    #+#             */
/*   Updated: 2020/09/14 10:01:58 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_char_field(t_plist *list, int i, int j, char *str)
{
	char c;

	c = list->zero ? '0' : ' ';
	if (list->dot)
	{
		if (list->prec >= list->nb_l)
			while (j++ < list->min_w - list->nb_l)
				str[i++] = c;
		if (list->string || (!list->string && list->prec >= 0))
			while (j++ < list->min_w - list->prec)
				str[i++] = c;
	}
	else if (!list->dot)
	{
		if (list->type == chr && list->data.c == '\0')
			j--;
		while (j++ < list->min_w - list->nb_l)
			str[i++] = c;
	}
	list->reslen = (list->type == chr
	&& list->data.c == '\0') ? i + 1 : i;
	return (i);
}

int	fill_nb_field(t_plist *list, int i, int j, char *str)
{
	char c;

	c = list->zero ? '0' : ' ';
	if (list->prec > list->nb_l)
		while (j++ < list->min_w - list->prec)
			str[i++] = c;
	else
		while (j++ < list->min_w - list->nb_l)
			str[i++] = c;
	return (i);
}

int	check_char_field(t_plist *list, int i, char *str)
{
	int j;

	j = 0;
	if (list->data.c == '\0' && !(list->dot && !list->prec))
		j++;
	if (list->dot && list->prec == 0 && !list->string)
		j++;
	i = fill_char_field(list, i, j, str);
	return (i);
}

int	check_nb_field(t_plist *list, long double nb, int i, char *str)
{
	int j;

	j = 0;
	if (list->sharp == 1 && list->mode != OCTAL && list->mode != 0
		&& nb != 0 && !list->pointer)
		j += 2;
	if (list->sharp && list->mode == OCTAL && nb != 0 &&
		!(list->dot && list->prec > list->nb_l))
		j++;
	if (list->pointer)
		j += 2;
	if (list->dot && nb < 0 && list->min_w > list->prec
		&& list->prec > list->nb_l - 1)
		j++;
	if ((list->plus || list->space) && nb >= 0 && list->mode == 0 && !list->uns)
		j++;
	if (list->dot && list->min_w > list->prec && !list->prec && !nb
		&& !list->f_type)
		j--;
	i = fill_nb_field(list, i, j, str);
	return (i);
}

int	check_field(t_plist *list, long double nb, int i, char *str)
{
	if (list->zero && nb < 0)
		str[i++] = '-';
	if ((list->min_w > list->nb_l
		|| (list->min_w >= list->nb_l && list->nb_l == 1 && list->dot))
		&& list->min_w > list->prec
		&& !list->minus
		&& list->prec >= 0
		&& list->type == nbr)
		i = check_nb_field(list, nb, i, str);
	if (list->type == chr && !list->minus)
		i = check_char_field(list, i, str);
	return (i);
}
