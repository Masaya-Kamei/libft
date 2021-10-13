/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:41:10 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:56:32 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static int	putchar_fd_test_framework(char c)
{
	int		pipe_fd[2];
	char	ans;

	pipe(pipe_fd);
	ft_putchar_fd(c, pipe_fd[1]);
	read(pipe_fd[0], &ans, 1);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (get_test_status(c == ans));
}

static int	putchar_fd_basic_test()	{ return (putchar_fd_test_framework('a')); }

int		ft_putchar_fd_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &putchar_fd_basic_test);
	return (launch_unit_tests(&test_list, "PUTCHAR_FD"));
}
