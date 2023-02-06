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
	double		distance;
	double		half_size;

	half_size = (ft_lstsize(data.stack_a) / 2);
	distance = count_distance(data);
	if ((check_if_sorted(data.stack_a) == 1))
		return (data);
	while (ft_lstsize(data.stack_a) != 1)
	{
		if ((distance >= half_size) && distance)
			data = reverse_rotate_a(data);
		else if (((distance < half_size)) && distance)
			data = rotate_a(data);
		if ((data.stack_a)->content == (smallest(data.stack_a)->content))
		{
			data = push_b(data);
			distance = count_distance(data);
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

int	count_distance(t_data data)
{
	t_list		*small;
	double		distance;
	t_list		*current;
	double		half_size;

	current = data.stack_a;
	small = smallest(data.stack_a);
	distance = 0;
	half_size = (ft_lstsize(data.stack_a) / 2);
	while (current->content != small->content)
	{
		distance++;
		current = current->next;
	}
	return (distance);
}
