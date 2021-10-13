/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:47:17 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:56:35 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

// Dependency
// ft_putendl_fd	:ft_putchar_fd

static int	putendl_fd_test_framework(char *str)
{
	int		pipe_fd[2];
	char	buf[101];
	int		readsize;

	pipe(pipe_fd);
	ft_putendl_fd(str, pipe_fd[1]);
	readsize = read(pipe_fd[0], buf, 100);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (buf[readsize - 1] == '\n')
		buf[readsize - 1] = '\0';
	else
		return (-1);
	return (get_test_status(strcmp(str, buf) == 0));
}

static int	putendl_fd_basic_test()	{ return (putendl_fd_test_framework("abcde")); }

int		ft_putendl_fd_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &putendl_fd_basic_test);
	return (launch_unit_tests(&test_list, "PUTENDL_FD"));
}
