/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:09:29 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:09:33 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_zero(t_plist *list, const char *fmt, va_list *ap)
{
	list->zero = 1;
	list->skip++;
	(void)fmt;
	(void)ap;
	return (1);
}
