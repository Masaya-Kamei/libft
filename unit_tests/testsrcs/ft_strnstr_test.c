/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:26:15 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/11 18:27:00 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <string.h>

static int	strnstr_test_framework(char *s1, char *s2, int len)
{
	return (get_test_status(strnstr(s1, s2, len) == ft_strnstr(s1, s2, len)));
}

static int	strnstr_hit_test()			{ return (strnstr_test_framework("abcde", "bcd", 4)); }
static int	strnstr_no_hit_test()		{ return (strnstr_test_framework("abcde", "bce", 4)); }
static int	strnstr_less_size_test()	{ return (strnstr_test_framework("abcde", "bc", 2)); }

int		ft_strnstr_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "hit", &strnstr_hit_test);
	load_unit_test(&test_list, "no hit", &strnstr_no_hit_test);
	load_unit_test(&test_list, "less size", &strnstr_less_size_test);
	return (launch_unit_tests(&test_list, "STRNSTR"));
}
