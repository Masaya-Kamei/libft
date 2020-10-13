/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 14:44:54 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/13 16:57:21 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*release(t_list *head, void (*del)(void *))
{
	if (head != NULL)
		ft_lstclear(&head, del);
	return (NULL);
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;
	void	*content;

	head = NULL;
	while (lst != NULL)
	{
		if (!(content = f(lst->content)))
			return (release(head, del));
		if (!(new = ft_lstnew(content)))
		{
			free(content);
			return (release(head, del));
		}
		if (head == NULL)
			head = new;
		else
			ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
