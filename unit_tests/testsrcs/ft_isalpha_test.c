/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:25:29 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/11 18:20:02 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <ctype.h>

static int	isalpha_test_framework(char c)
{
	return (get_test_status(isalpha(c) == ft_isalpha(c)));
}

static int	isalpha_alpha_small_test()	{ return (isalpha_test_framework('a')); }
static int	isalpha_alpha_large_test()	{ return (isalpha_test_framework('Z')); }
static int	isalpha_num_char_test()		{ return (isalpha_test_framework('5')); }

int		ft_isalpha_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "alpha small", &isalpha_alpha_small_test);
	load_unit_test(&test_list, "alpha large", &isalpha_alpha_large_test);
	load_unit_test(&test_list, "num char", &isalpha_num_char_test);
	return (launch_unit_tests(&test_list, "ISALPHA"));
}

