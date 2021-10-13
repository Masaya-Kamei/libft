/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:46:02 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:56:56 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

// Dependency
// ft_strdup	:ft_strlen, ft_strlcpy

static int	strdup_test_framework(char *s)
{
	const char	*str = strdup(s);
	const char	*ft_str = ft_strdup(s);
	const bool	flag = strcmp(str, ft_str) == 0;

	free((void *)str);
	free((void *)ft_str);
	return (get_test_status(flag));
}

static int	strdup_basic_test()	{ return (strdup_test_framework("abcde")); }

int		ft_strdup_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &strdup_basic_test);
	return (launch_unit_tests(&test_list, "STRDUP"));
}
