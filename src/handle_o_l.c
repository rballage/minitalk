/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:04:20 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:04:21 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_lo(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.lu = va_arg(*ap, unsigned long);
	list->mode = OCTAL;
	list->res = convert_octal((unsigned long long)list->data.lu);
	save = list->res;
	list->res = add_attributes(list, (long double)list->data.lu);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
