/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:08:52 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:08:53 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			set_field(t_plist *list, const char *fmt, va_list *ap)
{
	int		i;

	i = 0;
	if (list->has_star)
	{
		list->min_w = list->star;
		list->has_star = false;
	}
	else
	{
		list->min_w = ft_atoi(fmt);
		while (*fmt >= '0' && *fmt <= '9')
		{
			i++;
			fmt++;
		}
	}
	(void)ap;
	list->skip += i;
	return (i);
}
