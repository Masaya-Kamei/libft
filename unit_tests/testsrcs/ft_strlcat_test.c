/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:50:21 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:57:06 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

// Dependency
// ft_strlcat	:ft_strlen

static char	dst[20] = "abcde";
static char	ft_dst[20] = "abcde";

static int	strlcat_test_framework(char *dst, char *ft_dst, char *src, int size)
{
	return (get_test_status(
			strlcat(dst, src, size) == ft_strlcat(ft_dst, src, size)
			&& strcmp(dst, ft_dst) == 0));
}

static int	strlcat_basic_test()		{ return (strlcat_test_framework(dst, ft_dst, "12345", 20)); }
static int	strlcat_less_size_test()	{ return (strlcat_test_framework(dst, ft_dst, "12345", 3)); }
static int	strlcat_size_one_test()		{ return (strlcat_test_framework(dst, ft_dst, "12345", 1)); };

int		ft_strlcat_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &strlcat_basic_test);
	load_unit_test(&test_list, "less size", &strlcat_less_size_test);
	load_unit_test(&test_list, "size one", &strlcat_size_one_test);
	return (launch_unit_tests(&test_list, "STRLCAT"));
}
