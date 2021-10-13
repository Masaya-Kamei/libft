/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:21:31 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/11 18:20:56 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

// Dependency
// test 		:ft_lstnew, ft_lstclear

static int	lstsize_test_framework(t_list *lst, int lstsize)
{
	const bool	flag = ft_lstsize(lst) == lstsize;

	ft_lstclear(&lst, NULL);
	lst = NULL;
	return (get_test_status(flag));
}

static int	lstsize_basic_test()	{ return (lstsize_test_framework(alpha_lst(), 3)); }
static int	lstsize_null_lst_test()	{ return (lstsize_test_framework(NULL, 0)); }

int		ft_lstsize_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &lstsize_basic_test);
	load_unit_test(&test_list, "null lst", &lstsize_null_lst_test);
	return (launch_unit_tests(&test_list, "LSTSIZE"));
}
