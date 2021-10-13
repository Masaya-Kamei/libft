/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:14:48 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/12 18:32:25 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

// Dependency
// ft_calloc	:ft_bzero

static int	calloc_test_framework(int count, int size)
{
	int		*n;
	bool	flag;
	int		i;

	n = (int *)ft_calloc(count, size);
	flag = 1;
	for (i = 0; i < count; i++)
		flag &= n[i] == 0;
	free(n);
	return (get_test_status(flag));
}

static int	calloc_basic_test()	{ return (calloc_test_framework(3, sizeof(int))); }

int		ft_calloc_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &calloc_basic_test);
	return (launch_unit_tests(&test_list, "CALLOC"));
}


