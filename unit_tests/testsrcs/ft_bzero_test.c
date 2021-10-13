/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:09:05 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/12 11:56:44 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <string.h>

// Dependency
// ft_bzero		:ft_memset

static int	bzero_test_framework(void *s, int n)
{
	bool	flag;
	void	*ft_s;

	ft_s = memdup(s, n);
	bzero(s, n);
	ft_bzero(ft_s, n);
	flag = memcmp(s, ft_s, n) == 0;
	free(s);
	free(ft_s);
	return (get_test_status(flag));
}

static int	bzero_basic_test()	{ return (bzero_test_framework(memdup("12345", 6), 3)); }

int		ft_bzero_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &bzero_basic_test);
	return (launch_unit_tests(&test_list, "BZERO"));
}
