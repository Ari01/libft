/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:39:36 by user42            #+#    #+#             */
/*   Updated: 2020/11/21 17:54:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	(void)(del);
	t_list *new;

	new = NULL;
	if (f)
	{
		while (lst)
		{
			ft_lstadd_back(&new, ft_lstnew(f(lst->content)));
			lst = lst->next;
		}
	}
	return (new);
}
