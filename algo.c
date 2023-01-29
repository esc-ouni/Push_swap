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

// t_list  *smallest(t_data data)
// {
//     t_list  *n;
//     t_list  *n2;
//     t_list  *small;

//     n = data.stack_a;
//     n2 = n->next;
//     small = n;
//     while (n2)
//     {
//         if (n->content > n2->content)
//             small = n2;
//         n = n->next;
//         n2 = n->next;     
//     }
//     return (small);
// }

t_list  *biggest(t_data data)
{
    t_list  *n;
    t_list  *n2;
    t_list  *small;

    n = data.stack_a;
    n2 = n->next;
    // small = n;
    while (n2)
    {
        if (n->content <= n2->content)
            small = n2;
        n = n->next;
        n2 = n->next;     
    }
    return (small);
}

// t_data  algorithm(t_data data)
// {
//     t_list  *n;
//     t_list  *big;
//     int     l;
//     int     l2;

//     big = biggest(data);
//     l = ft_lstsize(data.stack_a);
//     n = smallest(data);
//     while(1)
//     {
//         if ((check_if_sorted(data.stack_a) == 1) && (ft_lstsize(data.stack_a) == l))
//             return (data);
//         if (ft_lstsize(data.stack_a) == 1)
//             break ;
//         if(data.stack_a == n)
//         {
//             data = push_b(data);
//             n = smallest(data);
//         }
//         data = rotate_a(data);
//     }
//     l2 = ft_lstsize(data.stack_b);
//     while(l2)
//     {
//         data = push_a(data);
//         l2--;
//     }
//     if (check_if_sorted(data.stack_a) == 0)
//         data = algorithm(data);
//     return (data);
// }

t_data  algorithm(t_data data)
{
    t_list  *n;
    // t_list  *big;
    int     l;
    // int     l2;

    // n = biggest(data);
    l = ft_lstsize(data.stack_a);
    n = biggest(data);
    if ((check_if_sorted(data.stack_a) == 1) && (ft_lstsize(data.stack_a) == l))
        return (data);
    while (ft_lstsize(data.stack_a) > ft_lstsize(data.stack_b))
    {
        if((data.stack_a)->content == (n->content))
        {
            data = push_b(data);
            n = biggest(data);
            ft_printf("\n%d\n", n->content);
        }
        data = rotate_a(data);
    }
    // l2 = ft_lstsize(data.stack_b);
    // while(l2)
    // {
    //     data = push_a(data);
    //     l2--;
    // }
    // if (check_if_sorted(data.stack_a) == 0)
    //     data = algorithm(data);
    return (data);
}