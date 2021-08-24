/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:05:19 by rballage          #+#    #+#             */
/*   Updated: 2020/01/10 12:25:36 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (lst && del)
	{
		tmp1 = *lst;
		while (tmp1)
		{
			tmp2 = tmp1->next;
			ft_lstdelone(tmp1, del);
			tmp1 = tmp2;
		}
		*lst = NULL;
	}
}
