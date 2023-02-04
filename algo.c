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

t_data  algo2(t_data data)
{
    t_list  *next;
    t_list  *best_mem;
    int     l;

    l = 0;
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
        l = 0;
        break ;
    }
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
    data = push_a(data);
    return (data);
}

t_data  moves_required(t_data data)
{
    t_list  *n;
    double  half_size;
    int l2;

    l2 = ft_lstsize(data.stack_a) / 2;
    half_size = (ft_lstsize(data.stack_b) / 2);
    n = data.stack_b;
    while(n)
    {
        n->mv_b = moves_to_be_on_top(data.stack_b, n, half_size);
        n->mv_a = moves_on_a(data, n, l2);
        n->mv_rr = 0; 
        n->mv_rrr = 0; 
        n->mv_required = abs(n->mv_a) + abs(n->mv_b) + 1;
        if (n->mv_a < 0 && n->mv_b < 0)
        {
            n->mv_rrr = abs(n->mv_a - n->mv_b);
            n->mv_b += n->mv_rrr;
            n->mv_a += n->mv_rrr;
        }
        else if (n->mv_a > 0 && n->mv_b > 0)
        {
            n->mv_rr = abs(n->mv_a - n->mv_b);
            n->mv_b -= n->mv_rr;
            n->mv_a -= n->mv_rr;
        }
        // n->mv_required = abs(n->mv_rr) + abs(n->mv_rrr) + abs(n->mv_a) + abs(n->mv_b) + 1;
        // printf("moves on b   : %d \n", n->mv_b);
        // printf("moves on a   : %d \n\n", n->mv_a);
        // printf("moves mv_rr  : %d \n\n", n->mv_rr);
        // printf("moves mv_rrr : %d \n\n", n->mv_rrr);
        // printf("total cost   : %d \n\n", n->mv_required);
        n = n->next;
    }
    return (data);
}

int moves_to_be_on_top(t_list *stack, t_list *node, double half_size)
{
    t_list  *n;
    double  distance;
    double l;

    distance = 0;
    n = stack;
    l = ft_lstsize(n);
    while(n->content != node->content && n->next)
    {
        n = n->next;
        distance++;
    }
    if (distance > half_size)
    {
        distance = ((l) - distance) * -1;
        // distance -= 1;
    }
    return(distance);
}


int moves_on_a(t_data data, t_list *n_b, double half_size)
{
    t_list  *n;
    t_list  *node;
    double     distance;

    distance = 0;
    n = data.stack_a;
    node = biggest(n);
    while(n)
    {
        if ((n_b->content < n->content) && (n->content < node->content))
        {
            node = n;
        }
        n = n->next;
    }
    // printf("\n\nnode in b  :%d", n_b->content);
    // printf("\nnode found :%d\n\n", node->content);
    distance = moves_to_be_on_top(data.stack_a, node, half_size);
    return(distance);
}

t_data  empty_a(t_data data)
{
    t_list  *big;

    big = biggest(data.stack_a);
    if ((check_if_sorted(data.stack_a) == 1))
        return (data);
    while (ft_lstsize(data.stack_a) != 1)
    {
        if((data.stack_a)->content < ((big->content)))
        {
            data = push_b(data);
        }
        else
            data = rotate_a(data);
        if ((ft_lstsize(data.stack_a) == 1))
            break ;
    }
    // data = empty_b(data, ft_lstsize(data.stack_b));
    return (data);
}