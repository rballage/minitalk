/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:00:07 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 22:53:23 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		assemble_str(t_plist *list, const char *fmt, char *str)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (fmt[j])
	{
		if (fmt[j] == '%' && fmt[j + 1])
		{
			if (list->reslen && list->type == chr && list->data.c
				== '\0' && list->nb_l == 1 && !list->string)
				while (k < list->reslen)
					*(str++) = list->res[k++];
			else
				while (list->res[k])
					*(str++) = list->res[k++];
			k = 0;
			j += list->skip;
			list = list->next;
		}
		else if (fmt[j] == '%' && !fmt[j + 1])
			j++;
		else
			*(str++) = fmt[j++];
	}
}

int			get_full_str_size(t_plist *list, const char *fmt)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (fmt[j])
	{
		if (fmt[j] == '%' && fmt[j + 1])
		{
			if (list->nb_l == 1 && list->type && !list->data.c && !list->string)
				i += list->reslen;
			else
				i += ft_strlen(list->res);
			j += list->skip;
			list = list->next;
		}
		else if (fmt[j] == '%' && !fmt[j + 1])
			break ;
		else
		{
			i++;
			j++;
		}
	}
	return (i);
}

int			write_full_str(t_plist *list, const char *fmt)
{
	int		i;
	char	*str;
	t_plist	*origin;
	int		size;

	size = 0;
	i = 0;
	origin = list;
	size = get_full_str_size(list, fmt);
	str = ft_strnew(size);
	list = origin;
	assemble_str(list, fmt, str);
	i = write(1, str, size);
	free(str);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_plist	*list;
	int		size;

	size = -1;
	list = new_list();
	va_start(ap, format);
	list = fill_list(format, &ap, list);
	size = write_full_str(list, format);
	va_end(ap);
	free_list(list);
	return (size);
}
