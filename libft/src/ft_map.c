/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:31:52 by rballage          #+#    #+#             */
/*   Updated: 2018/11/18 10:31:53 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *tab2;

	tab2 = NULL;
	i = -1;
	if (!(tab2 = malloc(length * sizeof(int))))
		return (0);
	while (++i < length)
		tab2[i] = f(tab[i]);
	return (tab2);
}
