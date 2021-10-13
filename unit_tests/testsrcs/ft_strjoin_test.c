/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:48:54 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/11 19:19:45 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <string.h>

// Dependency
// ft_strjoin	:ft_strlen, ft_strlcpy

static int	strjoin_test_framework(char *s1, char *s2, char *correct)
{
	const char	*str = ft_strjoin(s1, s2);
	const bool	flag = strcmp(str, correct) == 0;

	free((void *)str);
	return (get_test_status(flag));
}

static int	strjoin_basic_test()	{ return (strjoin_test_framework("abc", "def", "abcdef")); }

int		ft_strjoin_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &strjoin_basic_test);
	return (launch_unit_tests(&test_list, "STRJOIN"));
}
