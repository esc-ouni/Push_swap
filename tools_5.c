/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:15:42 by idouni            #+#    #+#             */
/*   Updated: 2023/02/04 20:15:45 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*smallest(t_list *stack)
{
	t_list	*small;
	t_list	*next;

	small = stack;
	next = stack->next;
	while (next != NULL)
	{
		if (next->content < small->content)
		{
			small = next;
		}
		next = next->next;
	}
	return (small);
}

t_list	*biggest(t_list *stack)
{
	t_list	*big;
	t_list	*next;

	big = stack;
	next = stack->next;
	while (next != NULL)
	{
		if (next->content > big->content)
		{
			big = next;
		}
		next = next->next;
	}
	return (big);
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

t_data	sort_small_qt(t_data data)
{
	if (data.stack_a == biggest(data.stack_a))
	{
		data = rotate_a(data);
		if (!check_if_sorted(data.stack_a))
			data = swap_a(data);
	}
	else if (biggest(data.stack_a) == ft_lstlast(data.stack_a))
	{
		if (!check_if_sorted(data.stack_a))
			data = swap_a(data);
	}
	else
	{
		if (!check_if_sorted(data.stack_a))
		{
			data = reverse_rotate_a(data);
			if (!check_if_sorted(data.stack_a))
				data = swap_a(data);
		}
	}
	return (data);
}

t_data	sort_5(t_data data)
{
	int			l;
	t_list		*small;
	t_list		*current;
	double		distance;
	double		half_size;

	current = NULL;
	l = ft_lstsize(data.stack_a);
	current = data.stack_a;
	small = smallest(data.stack_a);
	distance = 0;
	half_size = (l / 2);
	while (current->content != small->content)
	{
		distance++;
		current = current->next;
	}
	if ((check_if_sorted(data.stack_a) == 1))
		return (data);
	while (ft_lstsize(data.stack_a) != 1)
	{
		if ((distance >= half_size) && distance)
			data = reverse_rotate_a(data);
		else if (((distance < half_size)) && distance)
			data = rotate_a(data);
		if ((data.stack_a)->content == (small->content))
		{
			data = push_b(data);
			small = smallest(data.stack_a);
			distance = 0;
			current = data.stack_a;
			half_size = (ft_lstsize(current) / 2);
			while (current->content != small->content)
			{
				distance++;
				current = current->next;
			}
			if (ft_lstsize(data.stack_a) == 3)
			{
				data = sort_small_qt(data);
				break ;
			}
			if (check_if_sorted(data.stack_a))
				break ;
		}
	}
	return (data);
}
