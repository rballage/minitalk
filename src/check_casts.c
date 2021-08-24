/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_casts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:58:22 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:24:13 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		check_l_type(t_plist *list, const char *fmt, va_list *ap,
	int skip)
{
	int			i;
	static void (*f_l[]) (struct s_plist*, __builtin_va_list*,
	int) = {handle_f, handle_ld, handle_ld, handle_lu, handle_lo, handle_lx,
	handle_lx_maj, handle_f, handle_llu, handle_s, handle_p, handle_c};

	if ((i = search_setters(*(fmt + 1), "fdiuoxXfUspc")) != -1)
		f_l[i](list, ap, skip);
	else if (*(fmt + 1) == 'l')
		check_ll_type(list, fmt + 1, ap, skip + 1);
	else if (search_setters(*(fmt + 1), "hlLjz#$") != -1)
	{
		while (search_setters(*(fmt + 1), "hlLjz#$") != -1)
		{
			if (*(fmt + 1) == '#')
				list->sharp = 1;
			fmt++;
			skip++;
		}
		if ((i = search_setters(*(fmt + 1), "fdiuoxXfUspc")) != -1)
			f_l[i](list, ap, skip);
		else
			handle_null(list, fmt + 1, skip);
	}
	else
		handle_null(list, fmt + 1, skip);
}

static void		check_h_type(t_plist *list, const char *fmt, va_list *ap,
	int skip)
{
	int			i;
	static void (*f_h[])(struct s_plist*, __builtin_va_list*,
		int) = {handle_f, handle_hd, handle_hd, handle_hu, handle_ho,
		handle_hx, handle_hx_maj, handle_lu, handle_s, handle_p, handle_c};

	if (*(fmt + 1) == 'h')
		check_hh_type(list, fmt + 1, ap, skip + 1);
	else if (search_setters(*(fmt + 1), "lLjz#$") != -1)
	{
		while (search_setters(*(fmt + 1), "lLjz#$") != -1)
		{
			if (*(fmt + 1) == '#')
				list->sharp = 1;
			fmt++;
			skip++;
		}
		if ((i = search_setters(*(fmt + 1), "fdiuoxXUspc")) != -1)
			f_h[i](list, ap, skip);
		else
			handle_null(list, fmt + 1, skip);
	}
	else if ((i = search_setters(*(fmt + 1), "fdiuoxXUspc")) != -1)
		f_h[i](list, ap, skip);
	else
		handle_null(list, fmt + 1, skip);
}

static void		check_j_type(t_plist *list, const char *fmt, va_list *ap,
	int skip)
{
	int			i;
	static void (*f_j[])(struct s_plist*, __builtin_va_list*,
		int) = {handle_f, handle_lld, handle_llu, handle_llx, handle_llx_maj,
			handle_lld, handle_llo, handle_llu};

	i = 0;
	if ((i = search_setters(*(fmt + 1), "fduxXioU")) != -1)
		f_j[i](list, ap, skip);
	else if (search_setters(*(fmt + 1), "hlLjz#$") != -1)
	{
		while (search_setters(*(fmt + 1), "hlLjz#$") != -1)
		{
			if (*(fmt + 1) == '#')
				list->sharp = 1;
			fmt++;
			skip++;
		}
		if ((i = search_setters(*(fmt + 1), "fdiuoxXU")) != -1)
			f_j[i](list, ap, skip);
		else
			handle_null(list, fmt + 1, skip);
	}
	else
		handle_null(list, fmt + 1, 1);
}

static void		check_x_type(t_plist *list, const char *fmt, va_list *ap)
{
	static void (*f_x[]) (struct s_plist*, __builtin_va_list*,
		int) = {handle_d, handle_s, handle_p, handle_u, handle_c, handle_x,
		handle_x_maj, handle_f, handle_d, handle_o, handle_lu, handle_percent};
	int			i;

	i = 0;
	if ((i = search_setters(*fmt, "dspucxXfioU%")) != -1)
		f_x[i](list, ap, 1);
	else
	{
		list->noflag = 1;
		handle_null(list, fmt, 1);
	}
}

void			check_casts(t_plist *list, const char *fmt, va_list *ap)
{
	if (*fmt == 'l' || *fmt == 'z')
		check_l_type(list, fmt, ap, 2);
	else if (*fmt == 'h')
		check_h_type(list, fmt, ap, 2);
	else if (*fmt == 'j')
		check_j_type(list, fmt, ap, 2);
	else if (*fmt == 'L')
		check_l_maj_type(list, fmt, ap, 2);
	else
		check_x_type(list, fmt, ap);
}
