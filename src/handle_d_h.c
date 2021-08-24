/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:01:53 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:02:01 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_hd(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.s = (short)va_arg(*ap, int);
	list->res = ft_itoa(list->data.s);
	save = list->res;
	list->res = add_attributes(list, (long double)list->data.s);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
