/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:32:19 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:55:27 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static int	isdigit_test_framework(char c)
{
	return (get_test_status(isdigit(c) == ft_isdigit(c)));
}

static int	isdigit_num_test()		{ return (isdigit_test_framework(0)); }
static int	isdigit_num_char_test()	{ return (isdigit_test_framework('0')); }

int		ft_isdigit_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "num", &isdigit_num_test);
	load_unit_test(&test_list, "num char", &isdigit_num_char_test);
	return (launch_unit_tests(&test_list, "ISDIGIT"));
}
