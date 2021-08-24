/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sharp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:09:20 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:09:21 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_sharp(t_plist *list, const char *fmt, va_list *ap)
{
	list->sharp = 1;
	list->skip++;
	(void)fmt;
	(void)ap;
	return (1);
}
