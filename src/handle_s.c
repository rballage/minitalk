/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:05:49 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:05:51 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_s(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.str = va_arg(*ap, char*);
	if (list->data.str)
		list->res = ft_strdup(list->data.str);
	else
	{
		list->res = ft_strdup("(null)");
		list->data.c = '.';
	}
	save = list->res;
	list->type = chr;
	list->string = 1;
	list->res = add_attributes(list, 0);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
