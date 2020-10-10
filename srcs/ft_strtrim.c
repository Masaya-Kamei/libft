/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:36:45 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/10 13:27:29 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_start_index(char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (ft_strchr(set, s1[i]) != NULL && s1[i] != '\0')
		i++;
	return (i);
}

static int	get_end_index(char const *s1, char const *set)
{
	int		i;

	i = (int)ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) != NULL && s1[i] != '\0')
	{
		i--;
		if (i == -1)
			return ((int)ft_strlen(s1) - 1);
	}
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	start = get_start_index(s1, set);
	end = get_end_index(s1, set);
	if (!(str = (char *)malloc((end - start + 1) * sizeof(char) + 1)))
		return (NULL);
	if (end < start)
	{
		str[0] = '\0';
		return (str);
	}
	i = 0;
	while (i < end - start + 1)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
