/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:49:14 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/11 18:20:46 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

// Dependency
// test 		:ft_lstnew, ft_lstlast, ft_lstclear

static int	lstlast_test_framework(t_list *lst)
{
	bool	flag;

	if (!lst)
	{
		if (ft_lstlast(lst) == NULL)
			return (0);
		else
			return (-1);
	}
	flag = ft_lstlast(lst)->next == NULL;
	ft_lstclear(&lst, NULL);
	lst = NULL;
	return (get_test_status(flag));
}

static int	lstlast_basic_test()	{ return (lstlast_test_framework(alpha_lst())); }
static int	lstlast_null_test()		{ return (lstlast_test_framework(NULL)); }

int		ft_lstlast_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &lstlast_basic_test);
	load_unit_test(&test_list, "null", &lstlast_null_test);
	return (launch_unit_tests(&test_list, "LSTLAST"));
}
