/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:14:01 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/08 19:13:35 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_str_count(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	get_str_len(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		strs_index;
	int		len;
	char	**strs;

	if (!(strs = (char **)malloc((get_str_count(s, c) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	strs_index = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			len = get_str_len(&s[i], c);
			if (!(strs[strs_index] = (char *)malloc(len * sizeof(char) + 1)))
				return (NULL);
			ft_strlcpy(strs[strs_index], &s[i], len + 1);
			strs_index++;
			i += len;
		}
		else
			i++;
	}
	strs[strs_index] = NULL;
	return (strs);
}
