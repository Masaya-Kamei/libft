/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:57:41 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/11 19:00:52 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <ctype.h>

static int	tolower_test_framework(int c)
{
	return (get_test_status(tolower(c) == ft_tolower(c)));
}

static int	tolower_large_alpha_test()	{ return(tolower_test_framework('A')); }
static int	tolower_small_alpha_test()	{ return(tolower_test_framework('a')); }
static int	tolower_num_test()			{ return(tolower_test_framework('1')); }

int		ft_tolower_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "large alpha", &tolower_large_alpha_test);
	load_unit_test(&test_list, "small alpha", &tolower_small_alpha_test);
	load_unit_test(&test_list, "num", &tolower_num_test);
	return (launch_unit_tests(&test_list, "TOLOWER"));
}
