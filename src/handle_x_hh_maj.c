/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x_hh_maj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:07:05 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:07:06 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_hhx_maj(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.uc = (unsigned char)va_arg(*ap, unsigned int);
	list->mode = HEXA_HIGH;
	list->res = convert_hexa((unsigned int)list->data.uc, list);
	save = list->res;
	list->res = add_attributes(list, (long double)list->data.uc);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
