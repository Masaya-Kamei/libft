/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:19:16 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 17:08:32 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static int	isalnum_test_framework(char c)
{
	const int	ret = isalnum(c);
	const int	ft_ret = ft_isalnum(c);

	return (get_test_status((ret != 0 && ft_ret != 0) || (ret == 0 && ft_ret == 0)));
}

static int	isalnum_alpha_char_test()	{ return (isalnum_test_framework('z')); }
static int	isalnum_num_char_test()		{ return (isalnum_test_framework('0')); }
static int	isalnum_num_test()			{ return (isalnum_test_framework(0)); }

int		ft_isalnum_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "alpha char", &isalnum_alpha_char_test);
	load_unit_test(&test_list, "num char", &isalnum_num_char_test);
	load_unit_test(&test_list, "num", &isalnum_num_test);
	return (launch_unit_tests(&test_list, "ISALNUM"));
}

