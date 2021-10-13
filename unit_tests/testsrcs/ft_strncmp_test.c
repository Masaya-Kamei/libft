/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:20:09 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/11 18:18:21 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <string.h>

static int	strncmp_test_framework(char *s1, char *s2, int n)
{
	const int	ret = strncmp(s1, s2, n);
	const int	ft_ret = ft_strncmp(s1, s2, n);

	return (get_test_status((ret == ft_ret) || (ret > 0 && ft_ret > 0) || (ret < 0 && ft_ret < 0)));
}

static int	strncmp_same_str_test()		{ return (strncmp_test_framework("abc", "abc", 4)); }
static int	strncmp_diff_str_test()		{ return (strncmp_test_framework("abc", "abb", 4)); }
static int	strncmp_less_size_test()	{ return (strncmp_test_framework("abc", "abb", 2)); }

int		ft_strncmp_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "same str", &strncmp_same_str_test);
	load_unit_test(&test_list, "diff str", &strncmp_diff_str_test);
	load_unit_test(&test_list, "less size", &strncmp_less_size_test);
	return (launch_unit_tests(&test_list, "STRNCMP"));
}
