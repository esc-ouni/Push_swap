/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:24:38 by idouni            #+#    #+#             */
/*   Updated: 2023/02/01 11:24:41 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data  swap_a(t_data data)
{
    t_list  *n;
    t_list  *n2;

    if(ft_lstsize(data.stack_a) > 1)
    {
        n = data.stack_a;
        n2 = n->next;
        n->next = n2->next;
        n2->next = n;
        data.stack_a = n2;
        ft_printf("sa\n");
    }
    return (data);
}

t_data  swap_b(t_data data)
{
    t_list  *n;
    t_list  *n2;

    if(ft_lstsize(data.stack_b) > 1)
    {
        n = data.stack_b;
        n2 = n->next;
        n->next = n2->next;
        n2->next = n;
        data.stack_b = n2;
        ft_printf("sb\n");
    }
    return (data);
}

t_data  push_a(t_data data)
{
    t_list  *n;

    n = data.stack_b;
    if(ft_lstsize(data.stack_b) > 0)
    {
        ft_lstadd_front(&data.stack_a, ft_lstnew(data, n->content));
        data.stack_b = n->next;
        free(n);
        ft_printf("pa\n");
    }
    return (data);
}

t_data  push_b(t_data data)
{
    t_list  *n;

    n = data.stack_a;
    if(ft_lstsize(data.stack_a) > 0)
    {
        ft_lstadd_front(&data.stack_b, ft_lstnew(data, n->content));
        data.stack_a = n->next;
        free(n);
        ft_printf("pb\n");
    }
    return (data);
}

t_data  rotate_a(t_data data)
{
    t_list  *node;
    t_list  *last;

    if(ft_lstsize(data.stack_a) > 1)
    {
        node = data.stack_a;
        last = ft_lstlast(node);
        last->next = node;
        data.stack_a = node->next;
        node->next = NULL;
        ft_printf("ra\n");
    }
    return (data);
}

