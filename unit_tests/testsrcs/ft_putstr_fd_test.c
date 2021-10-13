/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:08:28 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/11 18:21:43 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <unistd.h>
#include <string.h>

static int	putstr_fd_test_framework(char *str)
{
	int		pipe_fd[2];
	char	buf[101];
	int		readsize;

	pipe(pipe_fd);
	ft_putstr_fd(str, pipe_fd[1]);
	readsize = read(pipe_fd[0], buf, 100);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	buf[readsize] = '\0';
	return (get_test_status(strcmp(str, buf) == 0));
}

static int	putstr_fd_basic_test()	{ return (putstr_fd_test_framework("abcde")); }

int		ft_putstr_fd_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &putstr_fd_basic_test);
	return (launch_unit_tests(&test_list, "PUTSTR_FD"));
}
