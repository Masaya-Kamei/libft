/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:30:11 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/10 13:59:31 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_len(int n)
{
	long	l;
	int		n_len;

	n_len = 0;
	l = n;
	if (l == 0)
		return (1);
	else if (l < 0)
	{
		l = -1 * l;
		n_len++;
	}
	while (l > 0)
	{
		n_len++;
		l = l / 10;
	}
	return (n_len);
}

char		*ft_itoa(int n)
{
	long	l;
	int		n_len;
	int		stop;
	char	*str;

	n_len = get_int_len(n);
	if (!(str = (char *)malloc(n_len * sizeof(char) + 1)))
		return (NULL);
	l = n;
	str[n_len--] = '\0';
	stop = 0;
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		l = -1 * l;
		stop = 1;
	}
	while (n_len >= stop && l != 0)
	{
		str[n_len--] = l % 10 + '0';
		l = l / 10;
	}
	return (str);
}
