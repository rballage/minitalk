/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:03:57 by rballage          #+#    #+#             */
/*   Updated: 2021/09/09 08:53:58 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 100

typedef enum	e_bool
{
	false,
	true
}				t_bool;

void			bufferise(char byte, int *index, t_bool error);
void			add_bit(char *byte, int *nth_bit, int signal);
void			clean(int *nth_bit, int *i, int *len, char *cnt, char *done);
void			setlen(int signal, char *counter, int *len);
int				parse_string(int sig, int *len, char *cnt, char *done, int pid);
void			handler(int sig, siginfo_t *info, void *context);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar(char ch);
void			ft_putnbr(int n);
void			ft_putstr(char *str);

#endif
