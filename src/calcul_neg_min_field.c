/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_neg_min_field.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:54:21 by rballage          #+#    #+#             */
/*   Updated: 2020/09/14 10:02:38 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			fill_char_field_minus(t_plist *list, int i, int j, char *str)
{
	char	c;

	c = ' ';
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
		if ((list->type == chr && list->nb_l == 1
		&& list->data.c != '\0') || list->string)
			j++;
		while (j++ <= list->min_w - list->nb_l)
			str[i++] = c;
	}
	list->reslen = i;
	return (i);
}

int			fill_nb_field_minus(t_plist *list, int i, int j, char *str)
{
	if (!(list->prec > list->nb_l) && list->nb_l == 1 && list->res[0] == '0'
	&& (!list->prec && list->dot) && !list->f_type)
		list->nb_l = 0;
	if (list->prec > list->nb_l)
		while (j++ < list->min_w - list->prec)
			str[i++] = ' ';
	else
		while (j++ < list->min_w - list->nb_l)
			str[i++] = ' ';
	str[i] = '\0';
	return (i);
}

int			check_nb_field_minus(t_plist *list, long double nb, int i,
	char *str)
{
	int		j;

	j = 0;
	if (!list->pointer && list->sharp == 1 && list->mode != OCTAL
		&& list->mode && nb != 0)
		j += 2;
	if (list->sharp == 1 && list->mode == OCTAL && list->mode && nb != 0
		&& !(list->dot && list->prec > list->nb_l))
		j++;
	if (list->pointer)
		j += 2;
	if ((list->plus == 1 || list->space) && nb >= 0 && list->mode == 0
	&& !list->uns)
		j++;
	if (list->dot && nb < 0 && list->min_w > list->prec
		&& list->prec > list->nb_l - 1)
		j++;
	i = fill_nb_field_minus(list, i, j, str);
	return (i);
}

int			check_char_field_minus(t_plist *list, int i, char *str)
{
	int		j;

	j = 0;
	if (list->data.c == '\0')
		j++;
	if (list->dot && list->prec == 0 && !list->string)
		j++;
	i = fill_char_field_minus(list, i, j, str);
	return (i);
}

int			check_field_minus(t_plist *list, long double nb, int i, char *str)
{
	if ((list->min_w > list->nb_l
		|| (list->min_w >= list->nb_l && list->nb_l == 1 && list->dot))
		&& list->min_w > list->prec
		&& list->minus
		&& list->type == nbr)
		i = check_nb_field_minus(list, nb, i, str);
	if (list->type == chr && list->minus)
		i = check_char_field_minus(list, i, str);
	return (i);
}
