/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d_ll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:02:37 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:02:38 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_lld(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.ll = va_arg(*ap, long long);
	list->res = ft_llitoa(list->data.ll);
	save = list->res;
	list->res = add_attributes(list, (long double)list->data.ll);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
