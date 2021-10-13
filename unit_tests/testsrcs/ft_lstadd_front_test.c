/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:00:43 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:55:42 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

// Dependency
// test 	:ft_lstnew, ft_lstclear

static int	lstadd_front_test_framework(t_list *lst, void *new_content)
{
	bool	flag;

	ft_lstadd_front(&lst, ft_lstnew(new_content));
	flag = strcmp(lst->content, new_content) == 0;
	ft_lstclear(&lst, NULL);
	lst = NULL;
	return (get_test_status(flag));
}

static int	lstadd_front_basic_test()	{ return (lstadd_front_test_framework(alpha_lst(), "cd")); }
static int	lstadd_front_null_test()	{ return (lstadd_front_test_framework(NULL, "cd")); }

int		ft_lstadd_front_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &lstadd_front_basic_test);
	load_unit_test(&test_list, "null", &lstadd_front_null_test);
	return (launch_unit_tests(&test_list, "LSTADD_FRONT"));
}
