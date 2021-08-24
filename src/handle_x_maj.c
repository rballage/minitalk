/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x_maj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:08:28 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:08:28 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_x_maj(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.ll = (long long)va_arg(*ap, unsigned int);
	list->mode = HEXA_HIGH;
	list->res = convert_hexa(list->data.ll, list);
	save = list->res;
	list->res = add_attributes(list, list->data.ll);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
