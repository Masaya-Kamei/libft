/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:17:42 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:56:20 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static int	memcpy_test_framework(char *dst, char *src, int n)
{
	void	*ft_dst;
	bool	flag;

	ft_dst = memdup(dst, n);
	flag = memcmp(memcpy(dst, src, n), ft_memcpy(ft_dst, src, n), n) == 0;
	free(dst);
	free(ft_dst);
	return (get_test_status(flag));
}

static int	memcpy_basic_test()			{ return (memcpy_test_framework(memdup("abc", 4), "123", 4)); }
static int	memcpy_less_size_test()		{ return (memcpy_test_framework(memdup("abc", 4), "123", 2)); }
static int	memcpy_include_null_test()	{ return (memcpy_test_framework(memdup("ab\0c", 5), "x\0yz", 4)); }

int		ft_memcpy_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &memcpy_basic_test);
	load_unit_test(&test_list, "less size", &memcpy_less_size_test);
	load_unit_test(&test_list, "include null", &memcpy_include_null_test);
	return (launch_unit_tests(&test_list, "MEMCPY"));
}
