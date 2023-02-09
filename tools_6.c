/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:19:11 by idouni            #+#    #+#             */
/*   Updated: 2023/02/04 20:19:14 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	moves_required(t_data data)
{
	t_list	*n;

	n = data.stack_b;
	while (n)
	{
		n = moves(data, n);
		n->mv_required = ft_abs(n->mv_rr) + ft_abs(n->mv_rrr) + \
		ft_abs(n->mv_a) + ft_abs(n->mv_b) + 1;
		n = n->next;
	}
	return (data);
}

t_list	*moves(t_data data, t_list *n)
{
	double	half_size;
	int		l2;

	l2 = ft_lstsize(data.stack_a) / 2;
	half_size = (ft_lstsize(data.stack_b) / 2);
	n->mv_b = moves_to_be_on_top(data.stack_b, n, half_size);
	n->mv_a = moves_on_a(data, n, l2);
	n->mv_rr = 0;
	n->mv_rrr = 0;
	n = count_rotation_on_both_stacks(n);
	return (n);
}

int	moves_to_be_on_top(t_list *stack, t_list *node, double half_size)
{
	t_list	*n;
	double	distance;
	double	l;

	distance = 0;
	n = stack;
	l = ft_lstsize(n);
	while (n->content != node->content && n->next)
	{
		n = n->next;
		distance++;
	}
	if (distance > half_size)
	{
		distance = ((l) - distance) * -1;
	}
	return (distance);
}

int	moves_on_a(t_data data, t_list *n_b, double half_size)
{
	t_list	*n;
	t_list	*node;
	double	distance;

	distance = 0;
	n = data.stack_a;
	node = biggest(n);
	while (n)
	{
		if ((n_b->content < n->content) && (n->content < node->content))
		{
			node = n;
		}
		n = n->next;
	}
	distance = moves_to_be_on_top(data.stack_a, node, half_size);
	return (distance);
}

t_list	*count_rotation_on_both_stacks(t_list *n)
{
	int	diff;

	diff = ft_abs(n->mv_a);
	if (ft_abs(n->mv_b) < ft_abs(n->mv_b))
		diff = ft_abs(n->mv_b);
	if (n->mv_a < 0 && n->mv_b < 0)
	{
		n->mv_rrr = diff;
		n->mv_b += diff;
		n->mv_a += diff;
	}
	else if (n->mv_a > 0 && n->mv_b > 0)
	{
		n->mv_rr = diff;
		n->mv_b -= diff;
		n->mv_a -= diff;
	}
	return (n);
}
