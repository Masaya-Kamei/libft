/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:43:35 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/12 18:37:26 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <string.h>
#include <ctype.h>

// Dependency
// test 		:ft_lstnew, ft_lstlast, ft_lstclear

static void	str_toupper(void *str)
{
	int		i;

	i = -1;
	while (((char *)str)[++i])
		((char *)str)[i] = toupper(((char *)str)[i]);
}

static int	lstiter_test_framework(t_list *lst, void (*f)(void *))
{
	char	*correct1;
	char	*correct2;
	bool	flag;

	if (!lst || !f)
	{
		ft_lstiter(lst, f);
		if (!f)
			ft_lstclear(&lst, free);
		return (0);
	}
	correct1 = strdup(lst->content);
	correct2 = strdup(ft_lstlast(lst)->content);
	f(correct1);
	f(correct2);
	ft_lstiter(lst, f);
	flag = (strcmp(lst->content, correct1) == 0) && (strcmp(ft_lstlast(lst)->content, correct2) == 0);
	free(correct1);
	free(correct2);
	ft_lstclear(&lst, free);
	lst = NULL;
	return (get_test_status(flag));
}

static int	lstiter_basic_test()		{ return (lstiter_test_framework(alpha_dup_lst(), str_toupper)); }
static int	lstiter_null_func_test()	{ return (lstiter_test_framework(alpha_dup_lst(), NULL)); }
static int	lstiter_null_lst_test()		{ return (lstiter_test_framework(NULL, str_toupper)); }

int		ft_lstiter_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &lstiter_basic_test);
	load_unit_test(&test_list, "null func", &lstiter_null_func_test);
	load_unit_test(&test_list, "null lst", &lstiter_null_lst_test);
	return (launch_unit_tests(&test_list, "LSTITER"));
}
