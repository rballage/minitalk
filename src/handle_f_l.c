/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_f_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:03:00 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:03:01 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_lf(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.ld = (long double)va_arg(*ap, double);
	list->res = ft_ftoa_ld((long double)list->data.ld,
	(((long double)list->data.ld < 0) ? '-' : 0), list);
	save = list->res;
	list->f_type = 1;
	list->res = add_attributes(list, (long double)list->data.ld);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
