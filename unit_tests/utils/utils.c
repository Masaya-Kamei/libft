/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:09:16 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/12 11:51:13 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <string.h>

void	free_double_ptr(char **strs)
{
	int		i;

	if (strs == NULL)
		return ;
	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

void	*memdup(const void *src, size_t n)
{
	void	*dst;

	dst = malloc(n);
	return (memcpy(dst, src, n));
}

t_list	*alpha_lst(void)
{
	t_list	*lst;

	lst = ft_lstnew("ab");
	lst->next = ft_lstnew("cd");
	lst->next->next = ft_lstnew("ef");
	return (lst);
}

t_list	*alpha_dup_lst(void)
{
	t_list	*lst;

	lst = ft_lstnew(strdup("ab"));
	lst->next = ft_lstnew(strdup("cd"));
	lst->next->next = ft_lstnew(strdup("ef"));
	return (lst);
}
