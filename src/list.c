/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:14:32 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 20:46:41 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_list(t_plist *list)
{
	list->next = NULL;
	list->res = NULL;
	list->skip = 1;
	list->undef = false;
	list->has_star = false;
	list->star = 0;
	list->noflag = 0;
	list->mode = 0;
	list->sharp = 0;
	list->minus = 0;
	list->plus = 0;
	list->zero = 0;
	list->space = 0;
	list->dot = 0;
	list->prec = 0;
	list->min_w = 0;
	list->string = 0;
	list->type = nbr;
	list->nb_l = 0;
	list->percent = 0;
	list->sharp_placed = 0;
	list->f_type = 0;
	list->pointer = 0;
	list->uns = 0;
}

t_plist			*new_list(void)
{
	t_plist		*list;

	if (!(list = malloc(sizeof(t_plist))))
		exit(0);
	init_list(list);
	return (list);
}

t_plist			*fill_list(const char *fmt, va_list *ap, t_plist *list)
{
	t_plist		*origin;

	origin = list;
	while (*fmt)
	{
		if (*fmt == '%' && fmt[1])
		{
			check_attributes(list, &(fmt[1]), ap);
			if (list->percent)
			{
				fmt++;
				while (*fmt && *fmt != '%')
					fmt++;
			}
			list->next = new_list();
			list = list->next;
		}
		fmt++;
	}
	return (origin);
}

void			free_list(t_plist *list)
{
	t_plist		*current;

	while (list)
	{
		current = list;
		free(list->res);
		list = list->next;
		free(current);
	}
}
