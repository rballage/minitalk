/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes_calculs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:53:38 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 17:53:41 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_attributes_length(t_plist *list, int i)
{
	if (list->sharp)
		i += 2;
	if (list->plus == 1 || list->space == 1)
		i += 1;
	if (list->dot)
		i += ft_abs(list->prec);
	if (list->min_w > 0)
		i += list->min_w;
	return (i);
}

int		check_normal_attributes(t_plist *list, long double nb, int i, char *str)
{
	if (list->dot && list->type == nbr)
		list->zero = 0;
	i = check_sharp_hexa_minus(list, nb, 0, str);
	if (list->zero)
		i = check_plus(list, nb, i, str);
	i = check_field(list, nb, i, str);
	i = check_sharp_hexa_field(list, nb, i, str);
	if (!list->zero)
		i = check_plus(list, nb, i, str);
	i = pad_r_zero(list, nb, i, str);
	i = check_sharp_octal(list, nb, i, str);
	i = check_sharp_hexa(list, nb, i, str);
	i = check_if_copy(list, nb, i, str);
	i = check_field_minus(list, nb, i, str);
	i = pad_l_spaces(list, i, str);
	return (i);
}

int		check_float_attributes(t_plist *list, long double nb, int i, char *str)
{
	if (list->zero)
		i = check_plus(list, nb, i, str);
	i = check_field(list, nb, i, str);
	if (!list->zero)
		i = check_plus(list, nb, i, str);
	i = check_if_copy(list, nb, i, str);
	if (list->f_type && !nb && list->dot && list->prec == 0)
	{
		ft_strcpy(&str[i], list->res);
		i += ft_strlen(list->res);
	}
	i = check_field_minus(list, nb, i, str);
	return (i);
}

char	*add_attributes(t_plist *list, long double nb)
{
	char	*str;
	int		attribute_size;

	if (!nb && !list->data.c && !list->nb_l && list->type && !list->string)
		list->nb_l = 1;
	else
		list->nb_l = ft_strlen(list->res);
	attribute_size = get_attributes_length(list, 0);
	str = ft_strnew(list->nb_l + attribute_size);
	if (list->f_type)
		check_float_attributes(list, nb, 0, str);
	else
		check_normal_attributes(list, nb, 0, str);
	return (str);
}
