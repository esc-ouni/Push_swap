/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:31:52 by idouni            #+#    #+#             */
/*   Updated: 2023/02/07 12:32:13 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	ch_rotate_b(t_data data)
{
	t_list	*node;
	t_list	*last;

	if (ft_lstsize(data.stack_b) > 1)
	{
		node = data.stack_b;
		last = ft_lstlast(node);
		last->next = node;
		data.stack_b = node->next;
		node->next = NULL;
	}
	return (data);
}

t_data	ch_reverse_rotate_a(t_data data)
{
	t_list	*node;
	t_list	*frst;
	t_list	*last;
	t_list	*prev;

	if (ft_lstsize(data.stack_a) > 1)
	{
		node = data.stack_a;
		frst = node;
		last = ft_lstlast(frst);
		while (frst != last)
		{
			prev = frst;
			frst = frst->next;
		}
		last->next = node;
		prev->next = NULL;
		data.stack_a = last;
	}
	return (data);
}

t_data	ch_reverse_rotate_b(t_data data)
{
	t_list	*node;
	t_list	*frst;
	t_list	*last;
	t_list	*prev;

	if (ft_lstsize(data.stack_b) > 1)
	{
		node = data.stack_b;
		frst = node;
		last = ft_lstlast(frst);
		while (frst != last)
		{
			prev = frst;
			frst = frst->next;
		}
		last->next = node;
		prev->next = NULL;
		data.stack_b = last;
	}
	return (data);
}
