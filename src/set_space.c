/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:09:25 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:09:26 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_space(t_plist *list, const char *fmt, va_list *ap)
{
	list->space = 1;
	list->skip++;
	(void)fmt;
	(void)ap;
	return (1);
}
