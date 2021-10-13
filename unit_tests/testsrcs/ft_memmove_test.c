/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:32:31 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:56:25 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static int	memmove_test_framework(char *dst, char *src, int n)
{
	void	*ft_dst;
	bool	flag;

	ft_dst = memdup(dst, n);
	flag = memcmp(memmove(dst, src, n), ft_memmove(ft_dst, src, n), n) == 0;
	free(dst);
	free(ft_dst);
	return (get_test_status(flag));
}

static int	memmove_basic_test() 		{ return (memmove_test_framework(memdup("abc", 4), "123", 4)); }
static int	memmove_same_ptr_test()		{ void *dst = memdup("abc", 4); return (memmove_test_framework(dst, dst + 2, 2)); }
static int	memmove_less_size_test()	{ return (memmove_test_framework(memdup("abc", 4), "123", 2)); }
static int	memmove_include_null_test()	{ return (memmove_test_framework(memdup("ab\0c", 5), "x\0yz", 5)); }

int		ft_memmove_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &memmove_basic_test);
	load_unit_test(&test_list, "same ptr", &memmove_same_ptr_test);
	load_unit_test(&test_list, "less size", &memmove_less_size_test);
	load_unit_test(&test_list, "include null", &memmove_include_null_test);
	return (launch_unit_tests(&test_list, "MEMMOVE"));
}
