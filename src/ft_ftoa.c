/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:27:16 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 22:56:29 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_sfloat	*init_sfloat(int zap, long long i_part, long double num)
{
	t_sfloat	*sfloat;

	if (!(sfloat = (t_sfloat*)malloc(sizeof(t_sfloat))))
		return (NULL);
	sfloat->zap = zap;
	sfloat->i_part = i_part;
	sfloat->num = num;
	sfloat->s = NULL;
	return (sfloat);
}

static char		*jftoa(char const *s1, int fp, char sign, t_sfloat *l)
{
	char		*str;
	size_t		len1;
	size_t		len2;
	int			tmp;

	tmp = fp;
	if (!s1)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(l->s);
	if (!(str = ft_memalloc(len1 + len2 + 2 + fp + (sign ? 1 : 0))))
		return (NULL);
	str[0] = sign;
	ft_memcpy((sign ? &(str[1]) : &(str[0])), s1, len1);
	str[len1 + (sign ? 1 : 0)] = ((*l->s) ? '.' : '\0');
	while (tmp--)
		str[len1 + 1 + tmp + (sign ? 1 : 0)] = '0';
	ft_memcpy((str + (len1 + 1 + fp) + (sign ? 1 : 0)), l->s, len2);
	ft_memdel((void **)&l->s);
	ft_memdel((void **)&s1);
	free(l);
	return (str);
}

static char		*fill_zero(int n)
{
	char		*res;
	int			i;

	i = 0;
	res = ft_strnew(n);
	while (i < n)
		res[i++] = '0';
	return (res);
}

static void		f_part(t_plist *l, t_sfloat *fl)
{
	int i;
	int nines;

	i = 0;
	nines = 0;
	while (i + fl->zap < l->prec && (long long)(fl->num * 10.0) >= 0)
	{
		((fl->num *= 10.0) < 1.0) ? fl->zap++ : i++;
		nines += ((((long long)(fl->num)) % 10 == 9) ? 1 : 0);
	}
	fl->num += ((((long long)(fl->num * 10.0)) % 10) >= 5) ? 1.0 : 0.0;
	(fl->num == 0.0) ? fl->zap-- : (fl->zap -= 0);
	if ((long long)fl->num == 0)
		i++;
	if (nines == l->prec && ((((long long)(fl->num * 10.0)) % 10) >= 5))
	{
		fl->s = fill_zero(l->prec);
		fl->i_part += 1;
	}
	else
		fl->s = ft_strjoinf((ft_llitoa((long long)(fl->num))), (fill_zero((
		l->prec - (i + fl->zap) > 0) ? l->prec - (i + fl->zap) : 0)));
}

char			*ft_ftoa_ld(long double num, char sign, t_plist *l)
{
	t_sfloat	*tf;

	if (num < 0.0)
		num *= -1.0;
	if (!(l->dot))
		l->prec = 6;
	tf = init_sfloat(0, ((long long)(num)), (num - (long long)num));
	if (l->prec > 0)
		f_part(l, tf);
	else
	{
		tf->i_part += ((tf->num * 10.0) >= 5.0) ? 1 : 0;
		tf->s = ft_strnew(1);
	}
	return (jftoa((ft_llitoa(tf->i_part)), ((ft_strlen(tf->s) + tf->zap)
	> (size_t)l->prec && tf->zap) ? tf->zap - 1 : tf->zap, sign, tf));
}
