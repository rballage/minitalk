/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:16:34 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:16:35 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_percent(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.c = '%';
	list->res = ft_strdup("%");
	save = list->res;
	list->type = chr;
	list->percent = 1;
	list->res = add_attributes(list, 0);
	list->skip += skip;
	(void)ap;
	if (save != list->res)
		free(save);
}
