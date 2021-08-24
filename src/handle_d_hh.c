/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d_hh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:02:11 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:02:12 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_hhd(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	if (list->undef)
	{
		list->data.ll = (long long)va_arg(*ap, int);
		list->res = ft_llitoa((long long)list->data.ll);
		save = list->res;
		list->res = add_attributes(list, (long double)list->data.ll);
	}
	else
	{
		list->data.c = (char)va_arg(*ap, int);
		list->res = ft_itoa((int)list->data.c);
		save = list->res;
		list->res = add_attributes(list, (long double)list->data.c);
	}
	list->skip += skip;
	if (save != list->res)
		free(save);
}
