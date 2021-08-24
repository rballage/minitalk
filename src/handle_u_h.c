/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:06:00 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:06:01 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_hu(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.us = (unsigned short)va_arg(*ap, unsigned int);
	list->res = ft_llitoa((long long)list->data.us);
	save = list->res;
	list->uns = 1;
	list->res = add_attributes(list, (long double)list->data.us);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
