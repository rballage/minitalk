/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:03:09 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:03:21 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_null(t_plist *list, const char *fmt, int ptr)
{
	char	*save;

	save = NULL;
	list->data.c = *fmt;
	if (!list->data.c)
	{
		list->data.c = '.';
		list->res = ft_strnew(0);
	}
	else
		list->res = ft_strdup(&(list->data.c));
	save = list->res;
	list->type = chr;
	list->skip += ptr;
	if (list->res[0] == '\0')
		list->skip--;
	if (!list->noflag)
		list->res = add_attributes(list, 0);
	if (save != list->res)
		free(save);
}
