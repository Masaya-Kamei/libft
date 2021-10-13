/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:18:03 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:56:03 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static int	lstnew_test_framework(char *content)
{
	t_list	*lst;
	bool	flag;

	lst = ft_lstnew(content);
	flag = strcmp(lst->content, content) == 0;
	free(lst);
	lst = NULL;
	return (get_test_status(flag));
}

static int	lstnew_basic_test()	{ return (lstnew_test_framework("abc")); }

int		ft_lstnew_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &lstnew_basic_test);
	return (launch_unit_tests(&test_list, "LSTNEW"));
}
