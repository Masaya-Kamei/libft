/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:04:18 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/11 18:21:14 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <string.h>

static int	memcmp_test_framework(char *buf1, char *buf2, int n)
{
	const int	ret1 = memcmp(buf1, buf2, n);
	const int	ret2 = ft_memcmp(buf1, buf2, n);

	return (get_test_status((ret1 == ret2) || (ret1 > 0 && ret2 > 0) || (ret1 < 0 && ret2 < 0)));
}

static int	memcmp_same_mem_test()		{ return (memcmp_test_framework("abcde", "abcde", 6)); }
static int	memcmp_diff_mem_test()		{ return (memcmp_test_framework("abcde", "abcxy", 6)); }
static int	memcmp_less_size_test()		{ return (memcmp_test_framework("abcde", "abcde", 3)); }
static int	memcmp_include_null_test()	{ return (memcmp_test_framework("ab\0cde", "ab\0cde", 7)); }

int		ft_memcmp_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "same mem", &memcmp_same_mem_test);
	load_unit_test(&test_list, "diff mem", &memcmp_diff_mem_test);
	load_unit_test(&test_list, "less size", &memcmp_less_size_test);
	load_unit_test(&test_list, "include null", &memcmp_include_null_test);
	return (launch_unit_tests(&test_list, "MEMCMP"));
}

////////////////////////////////////////////////////////////
// 引数の渡し方でmemcmpの返り値が変わる
// printf("CL(%d): %d\n", 5, memcmp("aiueo", "aiue1", 5));
// printf("FT(%d): %d\n", 5, ft_memcmp("aiueo", "aiue1", 5));

// int i = 5;
// printf("CL(%d): %d\n", i, memcmp("aiueo", "aiue1", i));
// printf("FT(%d): %d\n", i, ft_memcmp("aiueo", "aiue1", i));
//////////////////////////////////////////////////////////////
