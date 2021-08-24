/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:06:38 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:06:39 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_u(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.u = va_arg(*ap, unsigned int);
	list->res = ft_llitoa((long long)list->data.u);
	save = list->res;
	list->uns = 1;
	list->res = add_attributes(list, (long double)list->data.u);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
