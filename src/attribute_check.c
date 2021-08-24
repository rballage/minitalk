/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:53:22 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 21:22:14 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						chck_star(t_plist *list, const char *fmt, va_list *ap,
	t_bool field)
{
	if (*fmt == '*')
	{
		list->has_star = true;
		list->star = (int)va_arg(*ap, int);
		list->skip++;
		if (list->star < 0 && field)
		{
			list->minus = 1;
			list->star *= -1;
		}
		if (field)
			set_field(list, fmt, ap);
		return (1);
	}
	return (0);
}

void					check_attributes(t_plist *list, const char *fmt,
va_list *ap)
{
	static const char	attributes[] = "0123456789-+.# *$";
	static int			(*setters[])(t_plist*, const char *,
		__builtin_va_list*) = {&set_zero, &set_field, &set_field, &set_field,
		&set_field, &set_field, &set_field, &set_field, &set_field, &set_field,
		&set_minus, &set_plus, &set_precision, &set_sharp, &set_space};
	int					i;

	i = -1;
	fmt += chck_star(list, fmt, ap, true);
	while ((i = search_setters(*fmt, attributes)) > -1)
	{
		if (i != 15 && i != 16)
			fmt += (chck_star(list, fmt + 1, ap, i == 12 ? 0 : 1)
			+ setters[i](list, fmt, ap));
		else
			fmt++;
		if (*fmt == '$')
			list->skip++;
	}
	check_casts(list, fmt, ap);
}
