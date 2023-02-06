/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:24:12 by idouni            #+#    #+#             */
/*   Updated: 2023/02/01 11:24:20 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	rotate_b(t_data data)
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
		ft_printf("rb\n");
	}
	return (data);
}

t_data	reverse_rotate_a(t_data data)
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
		ft_printf("rra\n");
	}
	return (data);
}

t_data	reverse_rotate_b(t_data data)
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
		ft_printf("rrb\n");
	}
	return (data);
}

void	*h_malloc(t_data data, size_t s, void *p)
{
	p = malloc(s);
	if (!p)
	{
		ft_exit_with_error(data);
	}
	return (p);
}

t_data	put_min_on_top(t_data data)
{
	int	l;

	l = ft_lstsize(data.stack_a) / 2;
	l = moves_to_be_on_top(data.stack_a, smallest(data.stack_a), l);
	if (l < 0)
	{
		l = ft_abs(l);
		while (l)
		{
			data = reverse_rotate_a(data);
			l--;
		}
	}
	else
	{
		while (l)
		{
			data = rotate_a(data);
			l--;
		}
	}
	return (data);
}
