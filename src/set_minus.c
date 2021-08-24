/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_minus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:09:00 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:09:02 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_minus(t_plist *list, const char *fmt, va_list *ap)
{
	list->minus = 1;
	list->skip++;
	(void)fmt;
	(void)ap;
	return (1);
}
