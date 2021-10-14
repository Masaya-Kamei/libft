/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:40:28 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/14 15:42:02 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include "libunit.h"
# include "libft.h"
# include <ctype.h>
# include <string.h>

// launcher
int		ft_atoi_test_launcher(void);
int		ft_bzero_test_launcher(void);
int		ft_calloc_test_launcher(void);
int		ft_isalnum_test_launcher(void);
int		ft_isalpha_test_launcher(void);
int		ft_isascii_test_launcher(void);
int		ft_isdigit_test_launcher(void);
int		ft_isprint_test_launcher(void);
int		ft_itoa_test_launcher(void);
int		ft_lstadd_back_test_launcher(void);
int		ft_lstadd_front_test_launcher(void);
int		ft_lstclear_test_launcher(void);
int		ft_lstdelone_test_launcher(void);
int		ft_lstiter_test_launcher(void);
int		ft_lstlast_test_launcher(void);
int		ft_lstmap_test_launcher(void);
int		ft_lstnew_test_launcher(void);
int		ft_lstsize_test_launcher(void);
int		ft_memccpy_test_launcher(void);
int		ft_memchr_test_launcher(void);
int		ft_memcmp_test_launcher(void);
int		ft_memmove_test_launcher(void);
int		ft_memset_test_launcher(void);
int		ft_putchar_fd_test_launcher(void);
int		ft_putendl_fd_test_launcher(void);
int		ft_putnbr_fd_test_launcher(void);
int		ft_putstr_fd_test_launcher(void);
int		ft_split_test_launcher(void);
int		ft_strdup_test_launcher(void);
int		ft_striteri_test_launcher(void);
int		ft_strjoin_test_launcher(void);
int		ft_strlcat_test_launcher(void);
int		ft_strlcpy_test_launcher(void);
int		ft_strlen_test_launcher(void);
int		ft_strmapi_test_launcher(void);
int		ft_strncmp_test_launcher(void);
int		ft_strnstr_test_launcher(void);
int		ft_strrchr_test_launcher(void);
int		ft_strtrim_test_launcher(void);
int		ft_substr_test_launcher(void);
int		ft_tolower_test_launcher(void);
int		ft_toupper_test_launcher(void);

// utils
void	free_double_ptr(char **strs);
void	*memdup(const void *src, size_t n);
t_list	*alpha_lst(void);
t_list	*alpha_dup_lst(void);

#endif
