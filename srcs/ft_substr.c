/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:39:54 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/10 13:46:36 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	int		i;
	char	*sub;

	if (!(sub = (char *)malloc(len * sizeof(char) + 1)))
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s1))
	{
		sub[0] = '\0';
		return (sub);
	}
	i = 0;
	while (i < (int)len && s1[i] != '\0')
	{
		sub[i] = s1[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
