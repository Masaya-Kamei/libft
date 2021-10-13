/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:34:03 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/11 18:20:17 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <ctype.h>

static int	isprint_test_framework(char c)
{
	return (get_test_status(isprint(c) == ft_isprint(c)));
}

static int	isprint_space_test()		{ return (isprint_test_framework(' ')); }
static int	isprint_null_term_test()	{ return (isprint_test_framework('\0')); }

int		ft_isprint_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "space", &isprint_space_test);
	load_unit_test(&test_list, "null term", &isprint_null_term_test);
	return (launch_unit_tests(&test_list, "ISPRINT"));
}