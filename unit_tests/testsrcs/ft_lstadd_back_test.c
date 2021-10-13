/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:54:30 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:55:39 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

// Dependency
// ft_lstadd_back	:ft_lstlast
// test 			:ft_lstnew, ft_lstlast, ft_lstclear

static int	lstadd_back_test_framework(t_list *lst, void *new_content)
{
	bool	flag;

	ft_lstadd_back(&lst, ft_lstnew(new_content));
	flag = strcmp(ft_lstlast(lst)->content, new_content) == 0;
	ft_lstclear(&lst, NULL);
	lst = NULL;
	return (get_test_status(flag));
}

static int	lstadd_back_basic_test()	{ return (lstadd_back_test_framework(alpha_lst(), "xy")); }
static int	lstadd_back_null_test()		{ return (lstadd_back_test_framework(NULL, "xy")); }

int		ft_lstadd_back_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "null", &lstadd_back_null_test);
	load_unit_test(&test_list, "basic", &lstadd_back_basic_test);
	return (launch_unit_tests(&test_list, "LSTADD_BACK"));
}
