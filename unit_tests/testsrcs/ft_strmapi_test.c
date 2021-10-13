/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:20:53 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/11 16:23:47 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <string.h>

static char	fill_z_when_even_index(unsigned int i, char c)
{
	if (i % 2 == 0)
		return ('z');
	else
		return (c);
}

static int	strmapi_test_framework(char *s, char (*f)(unsigned int, char), char *correct)
{
	const char	*str = ft_strmapi(s, f);
	const bool	flag = strcmp(str, correct) == 0;

	free((void *)str);
	return (get_test_status(flag));
}

static int	strmapi_basic_test()	{ return (strmapi_test_framework("abcde", fill_z_when_even_index, "zbzdz")); }

int		ft_strmapi_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &strmapi_basic_test);
	return (launch_unit_tests(&test_list, "STRMAPI"));
}
