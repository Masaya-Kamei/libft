/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:48:50 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:54:45 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static int	atoi_test_framework(char *str)
{
	return (get_test_status(atoi(str) == ft_atoi(str)));
}

static int	atoi_basic_test() 				{ return (atoi_test_framework("42")); }
static int	atoi_include_char_test() 		{ return (atoi_test_framework("12ab12")); }
static int	atoi_minus_test()				{ return (atoi_test_framework("-42")); }
static int	atoi_minus_plus_test() 			{ return (atoi_test_framework("-+123")); }
static int	atoi_start_char_test() 			{ return (atoi_test_framework("a123")); }
static int	atoi_zero_test() 				{ return (atoi_test_framework("0")); }
static int	atoi_null_term_test() 			{ return (atoi_test_framework("")); }
static int	atoi_greater_int_test() 		{ return (atoi_test_framework("2147483648")); }
static int	atoi_less_int_test()			{ return (atoi_test_framework("-2147483649")); }
static int	atoi_greater_uint_test()		{ return (atoi_test_framework("4294967296")); }
static int	atoi_greater_long_long_test()	{ return (atoi_test_framework("9223372036854775808")); }
static int	atoi_less_long_long_test() 		{ return (atoi_test_framework("-9223372036854775809")); }

int		ft_atoi_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &atoi_basic_test);
	load_unit_test(&test_list, "include char", &atoi_include_char_test);
	load_unit_test(&test_list, "minus", &atoi_minus_test);
	load_unit_test(&test_list, "minus plus", &atoi_minus_plus_test);
	load_unit_test(&test_list, "start char", &atoi_start_char_test);
	load_unit_test(&test_list, "zero", &atoi_zero_test);
	load_unit_test(&test_list, "null term", &atoi_null_term_test);
	load_unit_test(&test_list, "greater int", &atoi_greater_int_test);
	load_unit_test(&test_list, "less int", &atoi_less_int_test);
	load_unit_test(&test_list, "greater uint", &atoi_greater_uint_test);
	load_unit_test(&test_list, "greater long long", &atoi_greater_long_long_test);
	load_unit_test(&test_list, "less long long", &atoi_less_long_long_test);
	return (launch_unit_tests(&test_list, "ATOI"));
}
