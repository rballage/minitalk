/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x_l_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:07:36 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:07:37 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_lx_maj(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.lu = va_arg(*ap, unsigned long);
	list->mode = HEXA_HIGH;
	list->res = convert_hexa((unsigned long long)list->data.lu, list);
	save = list->res;
	list->res = add_attributes(list, (long double)list->data.lu);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
