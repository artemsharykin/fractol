/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:16:32 by yalona            #+#    #+#             */
/*   Updated: 2019/09/19 18:55:09 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *tem;

	tem = (char *)str + ft_strlen(str);
	while (*tem != c)
	{
		if (tem == str)
		{
			return (0);
		}
		tem = tem - 1;
	}
	return (tem);
}
