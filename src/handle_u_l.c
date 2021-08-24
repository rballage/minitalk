/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:06:16 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:06:17 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_lu(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.lu = va_arg(*ap, unsigned long);
	list->res = ft_lutoa(list->data.lu);
	save = list->res;
	list->uns = 1;
	list->res = add_attributes(list, (long double)list->data.lu);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
