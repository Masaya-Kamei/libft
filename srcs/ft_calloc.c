/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:03:41 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/08 11:18:39 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	int		i;

	i = 0;
	p = (void *)malloc(count * size);
	if (p != NULL)
	{
		while (i < (int)count * (int)size)
			((unsigned char *)p)[i++] = '\0';
	}
	return (p);
}
