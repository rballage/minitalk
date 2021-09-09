/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:23:52 by rballage          #+#    #+#             */
/*   Updated: 2021/09/08 15:27:36 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	setlen(int signal, char *counter, int *len)
{
	if (signal == 1)
		*len |= (1 << (*counter));
	else if (signal == 0)
		*len &= ~(1 << (*counter));
}
