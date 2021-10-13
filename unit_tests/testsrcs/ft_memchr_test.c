/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:58:42 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:56:13 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static int	memchr_test_framework(char *buf, int ch, int n)
{
	return (get_test_status(memchr(buf, ch, n) == ft_memchr(buf, ch, n)));
}

static int	memchr_hit_char_test()		{ return (memchr_test_framework("abcde", 'c', 6)); }
static int	memchr_no_hit_test()		{ return (memchr_test_framework("abcde", 'z', 6)); }
static int	memchr_less_size_test()		{ return (memchr_test_framework("abcde", 'z', 3)); }
static int	memchr_include_null_test()	{ return (memchr_test_framework("ab\0cde", 'd', 7)); }

int		ft_memchr_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "hit char", &memchr_hit_char_test);
	load_unit_test(&test_list, "no hit", &memchr_no_hit_test);
	load_unit_test(&test_list, "less size", &memchr_less_size_test);
	load_unit_test(&test_list, "include null", &memchr_include_null_test);
	return (launch_unit_tests(&test_list, "MEMCHR"));
}
