/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:30:10 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 17:09:24 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static int	isascii_test_framework(int c)
{
	const int	ret = isascii(c);
	const int	ft_ret = ft_isascii(c);

	return (get_test_status((ret != 0 && ft_ret != 0) || (ret == 0 && ft_ret == 0)));
}

static int	isascii_alpha_test()		{ return (isascii_test_framework('a')); }
static int	isascii_null_term_test()	{ return (isascii_test_framework('\0')); }
static int	isascii_128_test()			{ return (isascii_test_framework(128)); }

int		ft_isascii_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "alpha", &isascii_alpha_test);
	load_unit_test(&test_list, "null term", &isascii_null_term_test);
	load_unit_test(&test_list, "128", &isascii_128_test);
	return (launch_unit_tests(&test_list, "ISASCII"));
}
