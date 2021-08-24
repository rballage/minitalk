/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:54:42 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 17:54:44 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_plus(t_plist *list, long double nb, int i, char *str)
{
	if (list->plus == 1 && nb >= 0 && !list->mode &&
		list->type == nbr && !list->uns)
		str[i++] = '+';
	i = check_space(list, nb, i, str);
	return (i);
}

int	check_space(t_plist *list, long double nb, int i, char *str)
{
	if (list->space == 1 && nb >= 0 && !list->mode
		&& !list->plus && list->type == nbr && !list->uns)
		str[i++] = ' ';
	return (i);
}
