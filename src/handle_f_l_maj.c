/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_f_l_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:02:53 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 21:48:45 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_lf_maj(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.ld = va_arg(*ap, long double);
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
	list->res = add_attributes(list, list->data.ld);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
