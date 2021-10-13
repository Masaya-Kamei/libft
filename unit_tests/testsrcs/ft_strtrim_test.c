/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:32:07 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:57:34 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

// Dependency
// ft_strtrim	:ft_strchr, ft_strdup, ft_strlen, ft_substr

static int	strtrim_test_framework(char *s1, char *set, char *correct)
{
	const char	*str = ft_strtrim(s1, set);
	const bool	flag = strcmp(str, correct) == 0;

	free((void *)str);
	return (get_test_status(flag));
}

static int	strtrim_basic_test()		{ return (strtrim_test_framework(" \n\nHello \t", " \n\t", "Hello")); }
static int	strtrim_all_trim_test()		{ return (strtrim_test_framework(" \n\n \t", " \n\t", "")); }
static int	strtrim_empty_str_test()	{ return (strtrim_test_framework("", " \n\t", "")); }

int		ft_strtrim_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &strtrim_basic_test);
	load_unit_test(&test_list, "all trim", &strtrim_all_trim_test);
	load_unit_test(&test_list, "empty str", &strtrim_empty_str_test);
	return (launch_unit_tests(&test_list, "STRTRIM"));
}
