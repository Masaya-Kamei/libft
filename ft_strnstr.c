/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:57:54 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/07 15:10:50 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int i;
	int j;

	i = 0;
	if (s2[0] == '\0')
		return (char *)(s1);
	while (s1[i] != '\0' && i < (int)len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < (int)len)
		{
			if (s2[j + 1] == '\0')
				return (char *)(s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
