/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:52:47 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 17:52:49 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_f(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.ld = (long double)va_arg(*ap, double);
	list->res = ft_ftoa_ld((long double)list->data.ld,
	(((long double)list->data.ld < 0) ? '-' : 0), list);
	if (list->dot && list->prec == 0 && list->sharp)
	{
		save = ft_strnew(ft_strlen(list->res) + 1);
		ft_strcpy(save, list->res);
		save[ft_strlen(list->res)] = '.';
		free(list->res);
		list->res = save;
	}
	save = list->res;
	list->f_type = 1;
	list->res = add_attributes(list, (long double)list->data.ld);
	if (save != list->res)
		free(save);
	list->skip += skip;
}
