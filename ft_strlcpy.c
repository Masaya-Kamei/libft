/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:12:00 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/06 17:50:33 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int i;

	i = 0;
	while (i < (int)size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i >= (int)size)
	{
		dst[i - 1] = '\0';
		while (src[i] != '\0')
			i++;
	}
	else
		dst[i] = '\0';
	return ((size_t)i);
}
