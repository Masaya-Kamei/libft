/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:05:18 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/13 13:56:38 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static int	putnbr_fd_test_framework(int nbr)
{
	int		pipe_fd[2];
	char	buf[101];
	int		readsize;

	pipe(pipe_fd);
	ft_putnbr_fd(nbr, pipe_fd[1]);
	readsize = read(pipe_fd[0], buf, 100);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	buf[readsize] = '\0';
	return (get_test_status(atoi(buf) == nbr));
}

static int	putnbr_fd_basic_test()	{ return (putnbr_fd_test_framework(42)); }
static int	putnbr_fd_minus_test()	{ return (putnbr_fd_test_framework(-42)); }
static int	putnbr_fd_zero_test()	{ return (putnbr_fd_test_framework(0)); }

int		ft_putnbr_fd_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &putnbr_fd_basic_test);
	load_unit_test(&test_list, "minus", &putnbr_fd_minus_test);
	load_unit_test(&test_list, "zero", &putnbr_fd_zero_test);
	return (launch_unit_tests(&test_list, "PUTNBR_FD"));
}
