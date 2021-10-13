/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:45:54 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/11 19:23:33 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

int	main(void)
{
	bool	status;

	put_header();
	status = 0;
	status |= ft_atoi_test_launcher() == -1;
	status |= ft_bzero_test_launcher() == -1;
	status |= ft_calloc_test_launcher() == -1;
	status |= ft_isalnum_test_launcher() == -1;
	status |= ft_isalpha_test_launcher() == -1;
	status |= ft_isascii_test_launcher() == -1;
	status |= ft_isdigit_test_launcher() == -1;
	status |= ft_isprint_test_launcher() == -1;
	status |= ft_itoa_test_launcher() == -1;
	status |= ft_lstadd_back_test_launcher() == -1;
	status |= ft_lstadd_front_test_launcher() == -1;
	status |= ft_lstclear_test_launcher() == -1;
	status |= ft_lstdelone_test_launcher() == -1;
	status |= ft_lstiter_test_launcher() == -1;
	status |= ft_lstlast_test_launcher() == -1;
	status |= ft_lstmap_test_launcher() == -1;
	status |= ft_lstnew_test_launcher() == -1;
	status |= ft_lstsize_test_launcher() == -1;
	status |= ft_memccpy_test_launcher() == -1;
	status |= ft_memchr_test_launcher() == -1;
	status |= ft_memcmp_test_launcher() == -1;
	status |= ft_memmove_test_launcher() == -1;
	status |= ft_memset_test_launcher() == -1;
	status |= ft_putchar_fd_test_launcher() == -1;
	status |= ft_putendl_fd_test_launcher() == -1;
	status |= ft_putnbr_fd_test_launcher() == -1;
	status |= ft_putstr_fd_test_launcher() == -1;
	status |= ft_split_test_launcher() == -1;
	status |= ft_strdup_test_launcher() == -1;
	status |= ft_striteri_test_launcher() == -1;
	status |= ft_strjoin_test_launcher() == -1;
	status |= ft_strlcat_test_launcher() == -1;
	status |= ft_strlcpy_test_launcher() == -1;
	status |= ft_strlen_test_launcher() == -1;
	status |= ft_strmapi_test_launcher() == -1;
	status |= ft_strncmp_test_launcher() == -1;
	status |= ft_strnstr_test_launcher() == -1;
	status |= ft_strrchr_test_launcher() == -1;
	status |= ft_strtrim_test_launcher() == -1;
	status |= ft_substr_test_launcher() == -1;
	status |= ft_tolower_test_launcher() == -1;
	status |= ft_toupper_test_launcher() == -1;
	return (status);
}
