/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:29:30 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:29:31 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_p(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->sharp = 1;
	list->pointer = 1;
	list->data.lu = va_arg(*ap, unsigned long);
	list->mode = HEXA_LOW;
	list->res = convert_hexa(list->data.lu, list);
	save = list->res;
	list->res = add_attributes(list, (long double)list->data.lu);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
