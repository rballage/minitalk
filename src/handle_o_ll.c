/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o_ll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:04:32 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:04:48 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_llo(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.llu = (unsigned long long)va_arg(*ap, long long);
	list->mode = OCTAL;
	list->res = convert_octal(list->data.llu);
	save = list->res;
	list->res = add_attributes(list, (long double)list->data.llu);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
