/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:01:04 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:57:45 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static int	toupper_test_framework(int c)
{
	return (get_test_status(toupper(c) == ft_toupper(c)));
}

static int	toupper_small_alpha_test()	{ return(toupper_test_framework('a')); }
static int	toupper_large_alpha_test()	{ return(toupper_test_framework('A')); }
static int	toupper_num_test()			{ return(toupper_test_framework('1')); }

int		ft_toupper_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "small alpha", &toupper_small_alpha_test);
	load_unit_test(&test_list, "large alpha", &toupper_large_alpha_test);
	load_unit_test(&test_list, "num", &toupper_num_test);
	return (launch_unit_tests(&test_list, "TOUPPER"));
}
