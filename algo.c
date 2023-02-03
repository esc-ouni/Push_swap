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
    data = moves_required(data);
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
        printf("moves on b : %d \n", n->mv_b);
        printf("moves on a : %d \n\n", n->mv_a);
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
    while (ft_lstsize(data.stack_a) != 4)
    {
        if((data.stack_a)->content < ((big->content) - 3))
        {
            data = push_b(data);
        }
        else
            data = rotate_a(data);
        if ((ft_lstsize(data.stack_a) == 4))
            break ;
    }
    // data = empty_b(data, ft_lstsize(data.stack_b));
    return (data);
}