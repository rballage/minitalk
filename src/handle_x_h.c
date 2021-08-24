/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:07:08 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:07:09 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_hx(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.us = (unsigned short)va_arg(*ap, unsigned int);
	list->mode = HEXA_LOW;
	list->res = convert_hexa((unsigned int)list->data.us, list);
	save = list->res;
	list->res = add_attributes(list, (long double)list->data.us);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
