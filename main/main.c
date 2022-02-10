/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:34:45 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/19 11:38:05 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = ft_strdup("abcde");
	if (str1 == NULL)
		return (0);
	str2 = ft_substr(str1, 2, 2);
	if (str2 == NULL)
		return (0);
	str3 = ft_strjoin(str1, str2);
	if (str3 == NULL)
		return (0);
	printf("%s %s %s\n", str1, str2, str3);
	free(str1);
	free(str2);
	free(str3);
	return (0);
}
