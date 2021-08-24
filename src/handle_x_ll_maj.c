/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x_ll_maj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:08:00 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:08:01 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_llx_maj(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.llu = (unsigned long long)va_arg(*ap, long long);
	list->mode = HEXA_HIGH;
	list->res = convert_hexa(list->data.llu, list);
	save = list->res;
	list->res = add_attributes(list, (long double)list->data.llu);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
