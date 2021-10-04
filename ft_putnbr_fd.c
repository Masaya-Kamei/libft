/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:56:26 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/04 18:00:07 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec_write_one_digit(unsigned int nbr, int fd)
{
	if (nbr >= 10)
		rec_write_one_digit(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		un = -1 * n;
	}
	else
		un = n;
	rec_write_one_digit(un, fd);
}
