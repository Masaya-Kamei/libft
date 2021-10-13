/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:00:54 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/12 16:34:27 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <string.h>

static void	fill_z_when_even_index(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = 'z';
}

static int	striteri_test_framework(char *s, void (*f)(unsigned int, char *), char *correct)
{
	bool	flag;

	ft_striteri(s, f);
	flag = strcmp(s, correct) == 0;
	free(s);
	return (get_test_status(flag));
}

static int	striteri_basic_test()		{ return (striteri_test_framework(strdup("abcde"), fill_z_when_even_index, "zbzdz")); }
static int	striteri_null_func_test()	{ return (striteri_test_framework(strdup("abcde"), NULL, "abcde")); }

int		ft_striteri_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &striteri_basic_test);
	load_unit_test(&test_list, "null func", &striteri_null_func_test);
	return (launch_unit_tests(&test_list, "STRITERI"));
}
