/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:08:44 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/08 17:29:42 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	pre_len;
	size_t	suf_len;
	char	*join;

	pre_len = ft_strlen(s1);
	suf_len = ft_strlen(s2);
	join = (char *)malloc((pre_len + suf_len) * sizeof(char) + 1);
	if (join == NULL)
		return (NULL);
	i = 0;
	while (i < (int)pre_len)
	{
		join[i] = s1[i];
		i++;
	}
	while (i < (int)pre_len + (int)suf_len)
	{
		join[i] = s2[i - (int)pre_len];
		i++;
	}
	join[i] = '\0';
	return (join);
}
