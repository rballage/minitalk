/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u_ll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:06:25 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:06:26 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_llu(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.ll = va_arg(*ap, long long);
	list->res = ft_lutoa(list->data.ll);
	save = list->res;
	list->uns = 1;
	list->res = add_attributes(list, (long double)list->data.ll);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
