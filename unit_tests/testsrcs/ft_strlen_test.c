/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:19:30 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:57:14 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static int	strlen_test_framework(char *s)
{
	return (get_test_status(strlen(s) == ft_strlen(s)));
}

static int	strlen_basic_test()		{ return (strlen_test_framework("abcde")); }

int		ft_strlen_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &strlen_basic_test);
	return (launch_unit_tests(&test_list, "STRLEN"));
}
