/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabhi <irabhi@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-24 14:34:33 by irabhi            #+#    #+#             */
/*   Updated: 2024-10-24 14:34:33 by irabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*node;

	if (!f || !lst || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		node = malloc(sizeof(t_list));
		if (!node)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		node->content = f(lst->content);
		node->next = NULL;
		ft_lstadd_back(&res, node);
		lst = lst->next;
	}
	return (res);
}
