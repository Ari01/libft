/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:39:36 by user42            #+#    #+#             */
/*   Updated: 2020/11/22 17:01:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;

	(void)(del);
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
