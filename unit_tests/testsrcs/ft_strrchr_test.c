/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:29:38 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:57:27 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static int	strrchr_test_framework(char *s, int c)
{
	return (get_test_status(strrchr(s, c) == ft_strrchr(s, c)));
}

static int	strrchr_hit_test()			{ return (strrchr_test_framework("abcabc", 'c')); }
static int	strrchr_no_hit_test()		{ return (strrchr_test_framework("abcabc", 'z')); }
static int	strrchr_null_term_test()	{ return (strrchr_test_framework("abcabc", '\0')); }

int		ft_strrchr_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "hit", &strrchr_hit_test);
	load_unit_test(&test_list, "no hit", &strrchr_no_hit_test);
	load_unit_test(&test_list, "null term", &strrchr_null_term_test);
	return (launch_unit_tests(&test_list, "STRRCHR"));
}
