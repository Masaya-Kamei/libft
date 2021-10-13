/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:41:58 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/11 18:21:51 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <string.h>

static int	strchr_test_framework(char *s, int c)
{
	return (get_test_status(strchr(s, c) == ft_strchr(s, c)));
}

static int	strchr_hit_test()		{ return (strchr_test_framework("abcde", 'c')); }
static int	strchr_no_hit_test()	{ return (strchr_test_framework("abcde", 'z')); }
static int	strchr_null_term_test()	{ return (strchr_test_framework("abcde", '\0')); }

int		ft_strchr_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "hit", &strchr_hit_test);
	load_unit_test(&test_list, "no hit", &strchr_no_hit_test);
	load_unit_test(&test_list, "null term", &strchr_null_term_test);
	return (launch_unit_tests(&test_list, "STRCHR"));
}
