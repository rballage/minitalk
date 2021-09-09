/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:23:20 by rballage          #+#    #+#             */
/*   Updated: 2021/09/08 15:27:03 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	clean(int *nth_bit, int *index, int *len, char *cnt, char *done)
{
	*nth_bit = 7;
	*cnt = 31;
	*len = 0;
	*done = 0;
	*index = 0;
}
