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

t_list  *smallest(t_list *stack)
{
    t_list  *small;
    t_list  *next;

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

t_list  *biggest(t_list *stack)
{
    t_list  *big;
    t_list  *next;

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

t_data put_min_on_top(t_data data)
{
    int l;

    l = ft_lstsize(data.stack_a) / 2;
    l = moves_to_be_on_top(data.stack_a, smallest(data.stack_a), l);
    if (l < 0)
    {
        l = abs(l);
        while(l)
        {
            data = reverse_rotate_a(data);
            l--;   
        }
    }
    else
    {
        while(l)
        {
            data = rotate_a(data);
            l--;   
        }
    }
    return (data);
}

t_data  sort_small_qt(t_data data)
{
    // if (check_if_sorted(data.stack_a))
    //     return (data);
    return (data);
}