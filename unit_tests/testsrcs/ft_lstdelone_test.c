/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:16:07 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:55:48 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

// Dependency
// test 		:ft_lstnew

static int	lstdelone_test_framework(t_list *lst, void (*del)(void *))
{
	ft_lstdelone(lst, del);
	return (0);
}

static int	lstdelone_free_func_test()	{ return (lstdelone_test_framework(ft_lstnew(strdup("aaa")), free)); }
static int	lstdelone_null_func_test()	{ return (lstdelone_test_framework(ft_lstnew("abc"), NULL)); }
static int	lstdelone_null_lst_test()	{ return (lstdelone_test_framework(NULL, free)); }

int		ft_lstdelone_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "free func", &lstdelone_free_func_test);
	load_unit_test(&test_list, "null func", &lstdelone_null_func_test);
	load_unit_test(&test_list, "null lst", &lstdelone_null_lst_test);
	return (launch_unit_tests(&test_list, "LSTDELONE"));
}
