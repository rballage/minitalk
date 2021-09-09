/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:24:24 by rballage          #+#    #+#             */
/*   Updated: 2021/09/08 15:27:25 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

int				parse_string(int sig, int *len, char *cnt, char *done, int pid)
{
	static int	nth_bit = 7;
	static char	byte = 0;
	static int	index;

	if (sig == -1)
	{
		bufferise(byte, &index, true);
		clean(&nth_bit, &index, len, cnt, done);
		return (1);
	}
	if (!index)
		index = *len;
	add_bit(&byte, &nth_bit, sig);
	if (nth_bit == -1)
	{
		bufferise(byte, &index, false);
		nth_bit = 7;
		if (index <= 0)
		{
			ft_putchar('\n');
			clean(&nth_bit, &index, len, cnt, done);
			kill(pid, SIGUSR1);
		}
	}
	return (1);
}
