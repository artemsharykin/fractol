/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:18:58 by yalona            #+#    #+#             */
/*   Updated: 2019/09/17 19:56:18 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *dest;

	if (!(dest = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		dest->content = NULL;
		dest->content_size = 0;
	}
	else
	{
		if (!(dest->content = malloc(content_size)))
		{
			free(dest);
			return (NULL);
		}
		ft_memcpy(dest->content, content, content_size);
		dest->content_size = content_size;
	}
	dest->next = NULL;
	return (dest);
}
