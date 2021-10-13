/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:10:56 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/11 19:05:18 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <string.h>

// Dependency
// ft_itoa	:ft_strdup

static int	itoa_test_framework(int n, char *correct)
{
	const char	*str = ft_itoa(n);
	const bool	flag = strcmp(str, correct) == 0;

	free((void *)str);
	return (get_test_status(flag));
}

static int	itoa_basic_test()	{ return (itoa_test_framework(42, "42")); }
static int	itoa_minus_test()	{ return (itoa_test_framework(-42, "-42")); }
static int	itoa_zero_test()	{ return (itoa_test_framework(0, "0")); }
static int	itoa_int_min_test()	{ return (itoa_test_framework(-2147483648, "-2147483648")); }

int		ft_itoa_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &itoa_basic_test);
	load_unit_test(&test_list, "minus", &itoa_minus_test);
	load_unit_test(&test_list, "zero", &itoa_zero_test);
	load_unit_test(&test_list, "int min", &itoa_int_min_test);
	return (launch_unit_tests(&test_list, "ITOA"));
}
