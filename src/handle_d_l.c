/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:02:24 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:02:25 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_ld(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.l = va_arg(*ap, long);
	list->res = ft_llitoa((long long)list->data.l);
	save = list->res;
	list->res = add_attributes(list, (long double)list->data.l);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
