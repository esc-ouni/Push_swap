/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:29:03 by idouni            #+#    #+#             */
/*   Updated: 2023/02/07 12:29:49 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	ch_swap_s(t_data data)
{
	t_list	*n;
	t_list	*n2;

	if ((ft_lstsize(data.stack_a) > 1) && (ft_lstsize(data.stack_b) > 1))
	{
		n = data.stack_a;
		n2 = n->next;
		n->next = n2->next;
		n2->next = n;
		data.stack_a = n2;
		n = data.stack_b;
		n2 = n->next;
		n->next = n2->next;
		n2->next = n;
		data.stack_b = n2;
	}
	return (data);
}

t_data	ch_rotate_r(t_data data)
{
	t_list	*node;
	t_list	*last;

	if ((ft_lstsize(data.stack_a) > 1) && (ft_lstsize(data.stack_b) > 1))
	{
		node = data.stack_a;
		last = ft_lstlast(node);
		last->next = node;
		data.stack_a = node->next;
		node->next = NULL;
		node = data.stack_b;
		last = ft_lstlast(node);
		last->next = node;
		data.stack_b = node->next;
		node->next = NULL;
	}
	return (data);
}

t_data	ch_reverse_rotate_r2(t_data data, t_rrr_data r)
{
	while (r.frst != r.last)
	{
		r.prev = r.frst;
		r.frst = r.frst->next;
	}
	r.last->next = r.node;
	r.prev->next = NULL;
	data.stack_a = r.last;
	r.node = data.stack_b;
	r.frst = r.node;
	r.last = ft_lstlast(r.frst);
	while (r.frst != r.last)
	{
		r.prev = r.frst;
		r.frst = r.frst->next;
	}
	r.last->next = r.node;
	r.prev->next = NULL;
	data.stack_b = r.last;
	return (data);
}

t_data	ch_reverse_rotate_r(t_data data)
{
	t_rrr_data	r;

	r.node = data.stack_a;
	r.frst = r.node;
	r.last = ft_lstlast(r.frst);
	if ((ft_lstsize(data.stack_a) > 1) && (ft_lstsize(data.stack_b) > 1))
	{
		data = ch_reverse_rotate_r2(data, r);
	}
	return (data);
}
