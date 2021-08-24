/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:04:56 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:04:57 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_o(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.u = va_arg(*ap, unsigned int);
	list->mode = OCTAL;
	list->res = convert_octal(list->data.u);
	save = list->res;
	list->res = add_attributes(list, (long double)list->data.u);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
