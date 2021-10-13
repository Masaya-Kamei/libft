/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:52:48 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/06 17:26:42 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_UTILS_H
# define LIBUNIT_UTILS_H

# include "libunit.h"

void		exit_with_errout(char *s);
t_ut_list	*ut_lstnew(char *test_name, t_test_func test_func);
void		ut_lstadd_back(t_ut_list **lst, t_ut_list *new);
int			ut_lstsize(t_ut_list *lst);
void		ut_lstclear(t_ut_list **lst);

#endif
