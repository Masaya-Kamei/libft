/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 10:44:46 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/07 13:13:15 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	int i;

	i = 0;
	while (i < (int)n)
	{
		if (((unsigned char *)buf)[i] == (unsigned char)ch)
			return (void *)(buf + i);
		i++;
	}
	return (NULL);
}
