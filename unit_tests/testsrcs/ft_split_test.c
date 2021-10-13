/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:10:23 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/11 19:18:25 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <string.h>

// Dependency
// ft_split		:ft_substr

static int	split_test_framework(char *s, char c, char **correct)
{
	char	**strs;
	int			i;
	bool		flag;

	strs = ft_split(s, c);
	i = -1;
	flag = 1;
	while (strs[++i])
		flag &= strcmp(strs[i], correct[i]) == 0;
	flag &= strs[i] == correct[i];
	free_double_ptr(strs);
	free_double_ptr(correct);
	return (get_test_status(flag));
}

static int	split_basic_test(void)
{
	char	**correct;

	correct = malloc(sizeof(char *) * 5);
	correct[0] = strdup("a");
	correct[1] = strdup("bb");
	correct[2] = strdup("ccc");
	correct[3] = strdup("d");
	correct[4] = NULL;
	return (split_test_framework("1a1bb11ccc1d11", '1', correct));
}

static int	split_all_split_char_test(void)
{
	char	**correct;

	correct = malloc(sizeof(char *));
	correct[0] = NULL;
	return (split_test_framework("111", '1', correct));
}

int		ft_split_test_launcher(void)
{
	t_ut_list	*test_list;

	test_list = NULL;
	load_unit_test(&test_list, "basic", &split_basic_test);
	load_unit_test(&test_list, "all split char", &split_all_split_char_test);
	return (launch_unit_tests(&test_list, "SPLIT"));
}
