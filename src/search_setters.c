/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_setters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:09:39 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:09:40 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				search_setters(char c, const char *flags)
{
	const char	*save;

	save = flags;
	while (*flags)
	{
		if (c == *flags)
			return (flags - save);
		flags++;
	}
	return (-1);
}
