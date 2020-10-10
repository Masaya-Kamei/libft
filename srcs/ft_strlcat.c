/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:49:33 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/10 15:08:41 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	int		s_index;

	d_len = ft_strlen(dst);
	if (d_len >= size)
		return (ft_strlen(src) + size);
	s_index = 0;
	while (((int)d_len + s_index) < (int)size && src[s_index] != '\0')
	{
		dst[(int)d_len + s_index] = src[s_index];
		s_index++;
	}
	if (((int)d_len + s_index) >= (int)size)
		dst[(int)d_len + s_index - 1] = '\0';
	else
		dst[(int)d_len + s_index] = '\0';
	return (d_len + ft_strlen(src));
}
