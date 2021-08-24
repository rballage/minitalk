/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_casts_llhh.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:58:35 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 21:44:15 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			check_ll_type(t_plist *list, const char *fmt, va_list *ap,
int skip)
{
	int			i;
	static void	(*function_ll[]) (struct s_plist*, __builtin_va_list*,
	int) = {handle_f, handle_lld, handle_lld, handle_llu, handle_llo,
		handle_llx, handle_llx_maj, handle_llu, handle_s, handle_p, handle_c};

	i = 0;
	if ((i = search_setters(*(fmt + 1), "fdiuoxXUspc")) != -1)
		function_ll[i](list, ap, skip);
	else if (search_setters(*(fmt + 1), "hlLjz#$") != -1)
	{
		while (search_setters(*(fmt + 1), "hlLjz#$") != -1)
		{
			if (*(fmt + 1) == '#')
				list->sharp = 1;
			fmt++;
			skip++;
		}
		if ((i = search_setters(*(fmt + 1), "fdiuoxXUspc")) != -1)
			function_ll[i](list, ap, skip);
		else
			handle_null(list, fmt + 1, skip);
	}
	else
		handle_null(list, fmt + 1, skip);
}

void			check_hh_type(t_plist *list, const char *fmt, va_list *ap,
int skip)
{
	int			i;
	static void	(*function_hh[])(struct s_plist*, __builtin_va_list*,
		int) = {handle_f, handle_hhd, handle_hhd, handle_hhu, handle_hho,
		handle_hhx, handle_hhx_maj, handle_llu, handle_s, handle_p, handle_c};

	i = 0;
	if ((i = search_setters(*(fmt + 1), "fdiuoxXUspc")) != -1)
		function_hh[i](list, ap, skip);
	else if (search_setters(*(fmt + 1), "hlLjz#$") != -1)
	{
		while (search_setters(*(fmt + 1), "hlLjz#$") != -1)
		{
			if (*(fmt + 1) == '#' || *(fmt + 1) == 'l')
				*(fmt + 1) != 'l' ? (list->sharp = 1)
				: (list->undef = 1);
			fmt++;
			skip++;
		}
		if ((i = search_setters(*(fmt + 1), "fdiuoxXUspc")) != -1)
			function_hh[i](list, ap, skip);
		else
			handle_null(list, fmt + 1, skip);
	}
	else
		handle_null(list, fmt + 1, skip);
}

void			check_l_maj_type(t_plist *list, const char *fmt,
va_list *ap, int skip)
{
	int			i;
	static void	(*function_l_maj[]) (struct s_plist*, __builtin_va_list*,
		int) = {handle_lf_maj, handle_lld, handle_lld, handle_llu, handle_llo,
		handle_llx, handle_llx_maj, handle_llu, handle_s, handle_p, handle_c};

	i = 0;
	if ((i = search_setters(*(fmt + 1), "fdiuoxXUspc")) != -1)
		function_l_maj[i](list, ap, skip);
	else if (search_setters(*(fmt + 1), "hlLjz#$") != -1)
	{
		while (search_setters(*(fmt + 1), "hlLjz#$") != -1)
		{
			if (*(fmt + 1) == '#')
				list->sharp = 1;
			fmt++;
			skip++;
		}
		if ((i = search_setters(*(fmt + 1), "fdiuoxXUspc")) != -1)
			function_l_maj[i](list, ap, skip);
		else
			handle_null(list, fmt + 1, skip);
	}
	else
		handle_null(list, fmt + 1, 2);
}
