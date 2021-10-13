/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:38:03 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/12 16:33:00 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <string.h>

static int	memset_test_framework(char *buf, int ch, int n)
{
	void	*ft_buf;
	bool	flag;

	ft_buf = memdup(buf, n);
	flag = memcmp(memset(buf, ch, n), ft_memset(ft_buf, ch, n), n) == 0;
	free(buf);
	free(ft_buf);
	return (get_test_status(flag));
}

static int	memset_basic_test()	{ return (memset_test_framework(memdup("abc", 4), '1', 4)); }

int		ft_memset_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &memset_basic_test);
	return (launch_unit_tests(&test_list, "MEMSET"));
}
