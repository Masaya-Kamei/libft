/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:42:03 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:56:09 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static int	memccpy_test_framework(char *dst, char *src, int c, int n)
{
	void	*ft_dst;
	bool	flag;

	ft_dst = memdup(dst, n);
	flag = (memccpy(dst, src, c, n) == ft_memccpy(ft_dst, src, c, n))
			&& (memcmp(dst, ft_dst, n) == 0);
	free(dst);
	free(ft_dst);
	return (get_test_status(flag));
}

static int	memccpy_basic_test()		{ return (memccpy_test_framework(memdup("abc", 4), "123", 'z', 4)); }
static int	memccpy_hit_char_test()		{ return (memccpy_test_framework(memdup("abc", 4), "123", 'b', 4)); }
static int	memccpy_less_size_test()	{ return (memccpy_test_framework(memdup("abc", 4), "123", 'c', 2)); }
static int	memccpy_include_null_test()	{ return (memccpy_test_framework(memdup("ab\0c", 5), "123", 'd', 4)); }

int		ft_memccpy_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &memccpy_basic_test);
	load_unit_test(&test_list, "hit char", &memccpy_hit_char_test);
	load_unit_test(&test_list, "less size", &memccpy_less_size_test);
	load_unit_test(&test_list, "include null", &memccpy_include_null_test);
	return (launch_unit_tests(&test_list, "MEMCCPY"));
}
