/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:33:28 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/12 10:33:35 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libunit_utils.h"

void	load_unit_test(t_ut_list **test_list, char *test_name, t_test_func f)
{
	t_ut_list	*new_list;

	new_list = ut_lstnew(test_name, f);
	if (new_list == NULL)
		exit_with_errout("malloc failed");
	ut_lstadd_back(test_list, new_list);
}
