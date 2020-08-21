/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:23:45 by yalona            #+#    #+#             */
/*   Updated: 2019/09/17 20:32:42 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (*alst && alst)
	{
		if ((*alst)->next == NULL)
			ft_lstdelone(alst, del);
		temp = (*alst);
		while ((temp))
		{
			ft_lstdelone(alst, del);
			*alst = temp->next;
			temp = (*alst);
		}
	}
}
