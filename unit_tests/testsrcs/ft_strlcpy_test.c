/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:13:15 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/12 16:45:20 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <string.h>

// Dependency
// ft_strlcpy	:ft_strlen

static int	strlcpy_test_framework(char *dst, char *src, int size)
{
	char	*ft_dst;
	bool	flag;

	ft_dst = strdup(dst);
	flag = (strlcpy(dst, src, size) == ft_strlcpy(ft_dst, src, size))
		&& (strcmp(dst, ft_dst) == 0);
	free(dst);
	free(ft_dst);
	return (get_test_status(flag));
}

static int	strlcpy_basic_test()		{ return (strlcpy_test_framework(strdup("abc"), "123", 4)); }
static int	strlcpy_less_size_test()	{ return (strlcpy_test_framework(strdup("abc"), "123", 2)); }
static int	strlcpy_more_size_test()	{ return (strlcpy_test_framework(strdup("abc"), "123", 6)); }

int		ft_strlcpy_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &strlcpy_basic_test);
	load_unit_test(&test_list, "less size", &strlcpy_less_size_test);
	load_unit_test(&test_list, "more size", &strlcpy_more_size_test);
	return (launch_unit_tests(&test_list, "STRLCPY"));
}

// 返り値は、src1の長さ
// sizeがdstの長さを超えるとエラー,対応しなくて良い
