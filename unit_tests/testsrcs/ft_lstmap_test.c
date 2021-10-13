/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:49:33 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:55:59 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

// Dependency
// ft_lstmap	:ft_lstnew, ft_lstclear, ft_lstadd_back
// test 		:ft_lstnew, ft_lstlast, ft_lstclear

static void	*strdup_with_toupper(void *str)
{
	char	*new_str;
	int		i;

	new_str = ft_strdup(str);
	i = -1;
	while (new_str[++i])
		new_str[i] = toupper(new_str[i]);
	return (new_str);
}

static int	lstmap_test_framework(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	bool	flag;
	char	*correct1;
	char	*correct2;

	if (!lst || !f)
	{
		flag = ft_lstmap(lst, f, del) == NULL;
		if (!f)
			ft_lstclear(&lst, free);
		return (get_test_status(flag));
	}
	correct1 = f(lst->content);
	correct2 = f(ft_lstlast(lst)->content);
	new_lst = ft_lstmap(lst, f, del);
	flag = (strcmp(correct1, new_lst->content) == 0)
			&& (strcmp(correct2, ft_lstlast(new_lst)->content) == 0);
	free((void *)correct1);
	free((void *)correct2);
	ft_lstclear(&lst, free);
	lst = NULL;
	ft_lstclear(&new_lst, free);
	new_lst = NULL;
	return (get_test_status(flag));
}

static int	lstmap_basic_test()		{ return (lstmap_test_framework(alpha_dup_lst(), strdup_with_toupper, free)); }
static int	lstmap_null_func_test()	{ return (lstmap_test_framework(alpha_dup_lst(), NULL, free)); }
static int	lstmap_null_lst_test()	{ return (lstmap_test_framework(NULL, strdup_with_toupper, free)); }

int		ft_lstmap_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &lstmap_basic_test);
	load_unit_test(&test_list, "null func", &lstmap_null_func_test);
	load_unit_test(&test_list, "null lst", &lstmap_null_lst_test);
	return (launch_unit_tests(&test_list, "LSTMAP"));
}
