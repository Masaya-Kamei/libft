/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:48:30 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/07 16:00:27 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && i < (int)n)
	{
		if ((s1[i] == '\0' && s2[i] == '\0') || (i + 1) == (int)n)
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}
