/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:57:35 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/11 19:22:12 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <string.h>

// Dependency
// ft_substr	:ft_strlen, ft_strdup, ft_strlcpy

static int	substr_test_framework(char *s1, int start, int len, char *correct)
{
	const char	*sub = ft_substr(s1, start, len);
	const bool	flag = strcmp(sub, correct) == 0;

	free((void *)sub);
	return (get_test_status(flag));
}

static int	substr_basic_test()		{ return(substr_test_framework("abcde", 2, 3, "cde")); }
static int	substr_more_len_test()	{ return(substr_test_framework("abcde", 0, 10, "abcde")); }
static int	substr_empty_str_test()	{ return(substr_test_framework("", 2, 3, "")); }
static int	substr_zero_len_test()	{ return(substr_test_framework("abcde", 2, 0, "")); }

int		ft_substr_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &substr_basic_test);
	load_unit_test(&test_list, "more len", &substr_more_len_test);
	load_unit_test(&test_list, "empty str", &substr_empty_str_test);
	load_unit_test(&test_list, "zero len", &substr_zero_len_test);
	return (launch_unit_tests(&test_list, "SUBSTR"));
}
