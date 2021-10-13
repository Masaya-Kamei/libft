/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:02:18 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/11 18:20:34 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

// Dependency
// ft_lstclear	:ft_lstdelone
// test 		:ft_lstnew

static int	lstclear_test_framework(t_list *lst, void (*del)(void *))
{
	ft_lstclear(&lst, del);
	lst = NULL;
	return (0);
}

static int	lstclear_basic_test()		{ return (lstclear_test_framework(alpha_dup_lst(), free)); }
static int	lstclear_null_func_test()	{ return (lstclear_test_framework(alpha_lst(), NULL)); }
static int	lstclear_null_lst_test()	{ return (lstclear_test_framework(NULL, free)); }

int		ft_lstclear_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "free func", &lstclear_basic_test);
	load_unit_test(&test_list, "null func", &lstclear_null_func_test);
	load_unit_test(&test_list, "null lst", &lstclear_null_lst_test);
	return (launch_unit_tests(&test_list, "LSTCLEAR"));
}
