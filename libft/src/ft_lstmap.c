/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:29:11 by rballage          #+#    #+#             */
/*   Updated: 2020/01/10 12:31:55 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (lst && f)
	{
		if (!(new = ft_lstnew(f(lst->content))))
			return (NULL);
		lst = lst->next;
		while (lst)
		{
			if (!(tmp = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&new, del);
				return (NULL);
			}
			ft_lstadd_back(&new, tmp);
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}
