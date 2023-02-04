/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:04:09 by idouni            #+#    #+#             */
/*   Updated: 2023/01/24 14:04:38 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data  algorithm(t_data data)
{
    data = empty_a(data);
    // data = sort_small_qt(data);
    data = moves_required(data);
    data = felina(data);
    return (data);
}

t_data  felina(t_data data)
{
    while(ft_lstsize(data.stack_b))
    {
        data = algo2(data);
        data = moves_required(data);
    }
    if(!check_if_sorted(data.stack_a))
        data = put_min_on_top(data);
    return (data);
}

t_data  algo2(t_data data)
{
    t_list  *next;
    t_list  *best_mem;

    best_mem = data.stack_b;
    next = best_mem->next;
    while(ft_lstsize(data.stack_b))
    {
        best_mem = data.stack_b;
        next = best_mem->next;
        while (next != NULL)
        {
            if (next->mv_required < best_mem->mv_required)
            {
                best_mem = next;
            }
            next = next->next;
        }
        break ;
    }
    data = rotate_both_stacks(data, best_mem);
    data = normal_instructions_stacks(data, best_mem);
    data = push_a(data);
    return (data);
}

t_data  rotate_both_stacks(t_data data, t_list *best_mem)
{
    int l;

    l = 0;
    l = abs(best_mem->mv_rr);
    while(l)
    {
        data = rotate_r(data);
        l--;
    }
    l = abs(best_mem->mv_rrr);
    while(l)
    {
        data = reverse_rotate_r(data);
        l--;
    }
    return (data);
}

t_data  normal_instructions_stacks(t_data data, t_list *best_mem)
{
    int l;

    l = 0;
    l = abs(best_mem->mv_a);
    while(l)
    {
        if (best_mem->mv_a < 0)
            data = reverse_rotate_a(data);
        else if (best_mem->mv_a > 0)
            data = rotate_a(data);
        l--;
    }
    l = abs(best_mem->mv_b);
    while(l)
    {
        if (best_mem->mv_b < 0)
            data = reverse_rotate_b(data);
        else if (best_mem->mv_b > 0)
            data = rotate_b(data);
        l--;
    }
    return (data);
}
