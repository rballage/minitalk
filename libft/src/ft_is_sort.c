/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:31:07 by rballage          #+#    #+#             */
/*   Updated: 2018/11/18 10:31:07 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_sort(int *tab, int length, int (*f) (int, int))
{
	int i;
	int c;
	int d;

	i = 0;
	c = 1;
	d = 1;
	while (i < length - 1 && c)
		(f(tab[i], tab[i + 1]) <= 0) ? ++i : (c = 0);
	i = 0;
	if (c == 1)
		return (1);
	while (i < length - 1 && d)
		(f(tab[i], tab[i + 1]) >= 0) ? ++i : (d = 0);
	if (d == 1)
		return (1);
	else
		return (0);
}
