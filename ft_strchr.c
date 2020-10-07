/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:19:01 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/07 13:34:12 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (1)
	{
		if (s[i] == c)
			return (char *)(s + i);
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (NULL);
}
