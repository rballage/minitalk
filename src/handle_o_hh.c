/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o_hh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:04:10 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:04:11 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_hho(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.uc = (unsigned char)va_arg(*ap, int);
	list->mode = OCTAL;
	list->res = convert_octal((unsigned int)list->data.uc);
	save = list->res;
	list->res = add_attributes(list, (long double)list->data.uc);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
