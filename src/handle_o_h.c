/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:03:58 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:04:00 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_ho(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.us = (unsigned short)va_arg(*ap, unsigned int);
	list->mode = OCTAL;
	list->res = convert_octal((unsigned int)list->data.us);
	save = list->res;
	list->res = add_attributes(list, (long double)list->data.us);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
