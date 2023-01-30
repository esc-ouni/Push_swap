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

t_list  *smallest(t_list *stack)
{
    t_list  *n;
    int     l;
    t_list  *n2;
    t_list  *small;
    
    n = stack;
    l = ft_lstsize(n) - 1;
    n2 = n->next;
    small = n;
    while (l)
    {
        if (n->content > n2->content)
            small = n2;
        n = n->next;
        n2 = n->next;
        l--;     
    }
    return (small);
}

t_data  algorithm(t_data data)
{
    t_list  *n;
    int     l;
    int     l2;

    l = ft_lstsize(data.stack_a);
    n = smallest(data.stack_a);
    if ((check_if_sorted(data.stack_a) == 1) && (ft_lstsize(data.stack_a) == l))
        return (data);
    while (ft_lstsize(data.stack_a) > 1)
    {
        if((data.stack_a)->content == (n->content))
        {
            data = push_b(data);
            n = smallest(data.stack_a);
            // ft_printf(clear"\n%d\n", n->content);
        }
        data = reverse_rotate_a(data);
    }
    l2 = l;
    while(l2)
    {
        data = push_a(data);
        l2--;
    }
    if (check_if_sorted(data.stack_a) == 0)
        data = algorithm(data);
    return (data);
}