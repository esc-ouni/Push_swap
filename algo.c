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
    t_list  *n;
    int  half_size;
    
    half_size = (ft_lstsize(data.stack_a) / 2);
    n = data.stack_a;
    while(n)
    {
        printf("distance from pa : %d h_s : %d\n", moves_on_b(data, n, half_size), half_size);
        n = n->next;
    }
    return (data);
}

int moves_on_b(t_data data, t_list *node, double half_size)
{
    t_list  *n;
    double  distance;

    distance = 0;
    n = data.stack_a;
    while(n->content != node->content && n->next)
    {
        n = n->next;
        distance++;
    }
    if (distance > half_size)
    {
        distance = ((half_size * 2) - distance) * -1;
    }
    return(distance);
}

// int moves_on_a(t_data data, t_list *node)
// {
//     return(distance);
// }




// t_data  algorithm(t_data data)
// {
//     data = empty_a(data);
//     return (data);
// }

// t_data  empty_a(t_data data)
// {
//     t_list  *big;

//     big = biggest(data.stack_a);
//     if ((check_if_sorted(data.stack_a) == 1))
//         return (data);
//     while (ft_lstsize(data.stack_a) != 4)
//     {
//         if((data.stack_a)->content < ((big->content) - 3))
//         {
//             data = push_b(data);
//         }
//         else
//             data = rotate_a(data);
//         if ((ft_lstsize(data.stack_a) == 4))
//             break ;
//     }
//     // data = empty_b(data, ft_lstsize(data.stack_b));
//     return (data);
// }