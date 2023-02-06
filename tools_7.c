/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:01:44 by idouni            #+#    #+#             */
/*   Updated: 2023/02/06 10:01:48 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int mid_value(t_data data)
{
    int     value;
    t_list  *n;
    t_list  *n1;
    int     l;
    int     t;

    value = 0;
    n = ft_lstmap(data, data.stack_a);
    n1 = n;
    l = ft_lstsize(n);
    while(l)
    {
        while(n->next)
        {
            if (n->next->content < n->content)
            {
                t = n->content;
                n->content = n->next->content;
                n->next->content = t;
            }
            n = n->next;
        }
        n = n1;
        l--;
    }
    l = ft_lstsize(n) / 2;
    while (value <= l)
    {
        value = n->content;
        n = n->next;
    }
    // ft_lstclear(n);
    return(value);
}