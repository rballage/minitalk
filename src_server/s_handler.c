/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:25:01 by rballage          #+#    #+#             */
/*   Updated: 2021/09/08 15:27:10 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void			handler(int sig, siginfo_t *info, void *context)
{
	static char	counter = 31;
	static int	len = 0;
	static char	finished = 0;
	static int	pid = 0;

	(void)context;
	if (pid != info->si_pid && len && pid)
		parse_string(-1, &len, &counter, &finished, pid);
	pid = info->si_pid;
	if (counter >= 0 && !finished)
	{
		setlen(((sig == SIGUSR1) ? 1 : 0), &counter, &len);
		if (--counter == -1)
		{
			finished = 1;
			if (!len)
			{
				ft_putchar('\n');
				counter = 31;
				finished = 0;
				kill(info->si_pid, SIGUSR1);
			}
		}
	}
	else parse_string(sig, &len, &counter, &finished, pid);
}
