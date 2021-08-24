/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u_hh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:06:07 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:06:08 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_hhu(t_plist *list, va_list *ap, int skip)
{
	char	*save;

	save = NULL;
	list->data.uc = (unsigned char)va_arg(*ap, unsigned int);
	list->res = ft_itoa((int)list->data.uc);
	save = list->res;
	list->uns = 1;
	list->res = add_attributes(list, (long double)list->data.uc);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
