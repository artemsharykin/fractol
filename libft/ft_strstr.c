/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:09:18 by yalona            #+#    #+#             */
/*   Updated: 2019/09/19 18:56:47 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	int i;
	int j;

	i = 0;
	if (*find == '\0' || ft_strlen(find) == 0)
		return ((char*)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (find[j] == str[i + j])
		{
			if (find[j + 1] == '\0')
			{
				return ((char*)&str[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
