/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:50:29 by jsebasti          #+#    #+#             */
/*   Updated: 2022/10/10 17:11:09 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*elem;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	new_lst = 0;
	while (lst)
	{
		tmp = f(lst->content);
		elem = ft_lstnew(tmp);
		if (!elem)
		{
			del(tmp);
			ft_lstclear(&new_lst, del);
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, elem);
	}
	return (new_lst);
}
