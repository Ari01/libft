/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:19:25 by user42            #+#    #+#             */
/*   Updated: 2020/11/22 17:27:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	lstdel(void *content)
{
	if (content)
		free(content);
}

void	free_lst_pointers(t_list **lst)
{
	if (lst)
	{
		if (*lst)
		{
			if (!(*lst)->next)
				free(*lst);
			else
			{
				free_lst_pointers(&(*lst)->next);
				free(*lst);
			}
		}
		*lst = NULL;
	}
}

void	print_list(t_list *lst)
{
	printf("list = ");
	while (lst)
	{
		printf("%s", lst->content);
		lst = lst->next;
	}
	printf("\n");
}

void	print_content(void *content)
{
	printf("content = %s\n", content);
}

void	test_lstnew(void *content, int i)
{
	t_list *new;
	new = ft_lstnew(content);

	if (!i)
	{
		printf("content = %s\n", (char *)content);
		printf("lst->content = %s\n", (char *)new->content);
	}
	else
	{
		printf("content = %d\n", *(int *)content);
		printf("lst->content = %d\n", *(int *)new->content);
	}
	if (new->content == content && new->next == NULL)
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
	free(new);
}

void	test_lstadd(t_list **alst, t_list *new, void (*add)(t_list **, t_list *), char *expected)
{
	t_list	*ite;
	int		i;
	int		test_res;

	add(alst, new);
	printf("expected = %s, ", expected);
	print_list(*alst);

	ite = *alst;
	test_res = 1;
	i = 0;
	while (ite)
	{
		if (ite->content && &expected[i])
		{
			if (ft_strncmp(ite->content, &expected[i], ft_strlen(ite->content)))
				test_res = 0;
		}
		ite = ite->next;
		i++;
	}
	if (test_res)
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
}

void	test_lstsize(t_list *lst, int expected)
{
	int size;

	size = ft_lstsize(lst);
	printf("expected size = %d, size = %d\n", expected, size);
	if (ft_lstsize(lst) != expected)
		printf("test ko\n\n");
	else
		printf("test ok\n\n");
}

void	test_lstlast(t_list *lst, t_list *expected)
{
	t_list *last;

	print_list(lst);
	last = ft_lstlast(lst);
	if (!lst && !last)
	{
		printf("empty list\n");
		printf("test ok\n\n");
	}
	else
	{
		printf("expected = %s, last = %s\n", expected->content, last->content);
		if (last != expected)
			printf("test ko\n\n");
		else
			printf("test ok\n\n");
	}
}

void	test_lstclear(t_list **lst, void (*del)(void *))
{
	print_list(*lst);
	ft_lstclear(lst, del);
	if (!(*lst))
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
}

void	*str_inc(void *content)
{
	if (content)
		*(char *)content += 1;
	return (content);
}

void	test_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *), char *expected)
{
	(void)(del);
	t_list *new;
	int i;

	new = ft_lstmap(lst, f, del);
	print_list(new);
	i = 0;
	while (new)
	{
		printf("expected = %c, new->content = %s\n", expected[i], new->content);
		if (new->content && expected)
		{
			if (ft_strncmp(new->content, &expected[i], ft_strlen(new->content)))
				printf("test ko\n\n");
			else
				printf("test ok\n\n");
		}
		new = new->next;
		i++;
	}
}

int		main(void)
{
	printf("\n--------------------- LSTNEW ---------------------\n");
	int i = 2147483647;
	test_lstnew("abc", 0);
	test_lstnew("", 0);
	test_lstnew(NULL, 0);
	test_lstnew(&i, 1);
	i = -2147483648;
	test_lstnew(&i, 1);
	i = 0;
	test_lstnew(&i, 1);

	printf("\n--------------------- LSTADDFRONT ---------------------\n");
	t_list *new = NULL;
	test_lstadd(&new, ft_lstnew("c"), &ft_lstadd_front, "c");
	test_lstadd(&new, ft_lstnew("b"), &ft_lstadd_front, "bc");
	test_lstadd(&new, ft_lstnew("a"), &ft_lstadd_front, "abc");
	test_lstadd(&new, ft_lstnew(0), &ft_lstadd_front, "\0abc");
	test_lstadd(&new, NULL, &ft_lstadd_front, "\0abc");
	free_lst_pointers(&new);

	printf("\n--------------------- LSTSIZE ---------------------\n");
	new = NULL;
	test_lstsize(new, 0);
	ft_lstadd_front(&new, ft_lstnew("b"));
	test_lstsize(new, 1);
	ft_lstadd_front(&new, ft_lstnew("c"));
	test_lstsize(new, 2);
	ft_lstadd_front(&new, ft_lstnew("2147483647"));
	ft_lstadd_front(&new, ft_lstnew("-2147483648"));
	ft_lstadd_front(&new, ft_lstnew(0));
	test_lstsize(new, 5);
	free_lst_pointers(&new);

	printf("\n--------------------- LSTLAST ---------------------\n");
	new = NULL;
	test_lstlast(new, 0);

	t_list *last = ft_lstnew("b");
	ft_lstadd_back(&new, last);
	test_lstlast(new, last);

	last = ft_lstnew("c");
	ft_lstadd_back(&new, last);
	test_lstlast(new, last);

	last = ft_lstnew(0);
	ft_lstadd_back(&new, last);
	test_lstlast(new, last);
	free_lst_pointers(&new);

	printf("\n--------------------- LSTADDBACK ---------------------\n");
	new = NULL;
	test_lstadd(&new, ft_lstnew("a"), &ft_lstadd_back, "a");
	test_lstadd(&new, ft_lstnew("b"), &ft_lstadd_back, "ab");
	test_lstadd(&new, ft_lstnew("c"), &ft_lstadd_back, "abc");
	test_lstadd(&new, ft_lstnew(0), &ft_lstadd_back, "abc\0");
	test_lstadd(&new, NULL, &ft_lstadd_back, "abc\0");
	free_lst_pointers(&new);

	printf("\n--------------------- LSTCLEAR ---------------------\n");
	new = NULL;
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("a")));
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("b")));
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("c")));
	ft_lstadd_back(&new, ft_lstnew(0));
	ft_lstadd_back(&new, NULL);
	test_lstclear(&new, &lstdel);

	printf("\n--------------------- LSTITER ---------------------\n");
	new = NULL;
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("a")));
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("b")));
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("c")));
	ft_lstadd_back(&new, ft_lstnew(0));
	ft_lstadd_back(&new, NULL);
	ft_lstiter(new, &print_content);

	printf("\n--------------------- LSTMAP ---------------------\n");
	test_lstmap(new, &str_inc, &lstdel, "bcd\0");
	ft_lstclear(&new, &lstdel);

	return (0);
}
