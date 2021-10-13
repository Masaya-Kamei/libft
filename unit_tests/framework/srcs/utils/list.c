/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:58:14 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/06 17:25:44 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

t_ut_list	*ut_lstnew(char *test_name, t_test_func test_func)
{
	t_ut_list	*lst;

	lst = (t_ut_list *)malloc(sizeof(t_ut_list));
	if (lst == NULL)
		return (NULL);
	lst->name = test_name;
	lst->test_func = test_func;
	lst->next = NULL;
	return (lst);
}

static t_ut_list	*ut_lstlast(t_ut_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ut_lstadd_back(t_ut_list **lst, t_ut_list *new)
{
	t_ut_list	*last;

	if (lst == NULL)
		return ;
	else if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ut_lstlast(*lst);
	last->next = new;
}

int	ut_lstsize(t_ut_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	ut_lstclear(t_ut_list **lst)
{
	t_ut_list	*next;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}
