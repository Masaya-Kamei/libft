/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:39:54 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/18 16:16:19 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	s_len;

	if (s1 == NULL)
		return (NULL);
	s_len = ft_strlen(s1);
	if ((start >= s_len) || len == 0)
		return (ft_strdup(""));
	if (s_len < (start + len))
		len = s_len - start;
	if (!(sub = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s1[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
