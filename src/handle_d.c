/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:02:45 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:02:47 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_d(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.i = va_arg(*ap, int);
	list->res = ft_itoa(list->data.i);
	save = list->res;
	list->res = add_attributes(list, (long double)list->data.i);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
