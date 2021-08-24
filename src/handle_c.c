/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:01:47 by rballage          #+#    #+#             */
/*   Updated: 2020/09/14 00:07:14 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_c(t_plist *list, va_list *ap, int skip)
{
	char *save;

	save = NULL;
	list->data.c = (unsigned char)va_arg(*ap, int);
	list->res = ft_strnew(1);
	save = list->res;
	list->res[0] = list->data.c;
	list->type = chr;
	list->res = add_attributes(list, 0);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
