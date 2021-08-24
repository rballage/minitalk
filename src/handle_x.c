/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:08:36 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:08:37 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_x(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.ll = (long long)va_arg(*ap, unsigned int);
	list->mode = HEXA_LOW;
	list->res = convert_hexa(list->data.ll, list);
	save = list->res;
	list->res = add_attributes(list, list->data.ll);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
