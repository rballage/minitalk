/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:39:42 by rballage          #+#    #+#             */
/*   Updated: 2020/01/10 12:28:54 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			word_count(char const *str, char c)
{
	int				i;
	int				nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			nb++;
		i++;
	}
	return (nb);
}

static int			word_len(const char *str, char c)
{
	int				i;

	i = 0;
	while (*str == c)
		str++;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static const char	*word_copy(const char *str, char *tab, char c)
{
	int				i;

	i = -1;
	while (*str == c)
		str++;
	while (*str != c && *str != '\0')
		tab[++i] = *(str++);
	tab[++i] = '\0';
	return (str);
}

char				**ft_split(char const *s, char c)
{
	int				i;
	char			**tab;
	int				nb;

	if (!s)
		return (NULL);
	i = -1;
	nb = word_count(s, c);
	if (!(tab = (char**)malloc(sizeof(*tab) * (nb + 1))))
		return (NULL);
	while (++i < nb)
	{
		if (!(tab[i] = (char*)malloc(sizeof(**tab) * word_len(s, c) + 1)))
			return (0);
		s = word_copy(s, tab[i], c);
	}
	tab[i] = 0;
	return (tab);
}
