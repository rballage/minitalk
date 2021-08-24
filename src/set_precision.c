/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:09:13 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 20:55:10 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_precision(t_plist *list, const char *fmt, va_list *ap)
{
	int	i;

	i = 1;
	list->dot = 1;
	(void)ap;
	if (*fmt && fmt[i] && fmt[i] >= '0' && fmt[i] <= '9')
	{
		list->prec = ft_atoi(fmt + 1);
		while (fmt[i] >= '0' && fmt[i] <= '9')
			++i;
	}
	else if (list->has_star)
	{
		list->prec = list->star >= 0 ? list->star : --(list->dot);
		list->has_star = false;
	}
	else
		list->prec = 0;
	list->skip += i;
	return (i);
}
