/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valuechecker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:42:39 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/03 20:50:47 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_valuechecker(t_list *lst, t_list *lis)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lis;
		while (tmp)
		{
			if (lst->content == lis->content)
				return (1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}

int	ft_valuethere(int content, t_list *lis)
{
	while (lis)
	{
		if (content == lis->content)
			return (1);
		lis = lis->next;
	}
	return (0);
}