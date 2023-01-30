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

t_data  algorithm(t_data data)
{
    t_list  *small;
    // t_list  *current;
    int     l;
    // int     distance = 0;
    // int     half_size;
    int     l2;

    l = ft_lstsize(data.stack_a);
    small = smallest(data.stack_a);
    if ((check_if_sorted(data.stack_a) == 1) && (ft_lstsize(data.stack_a) == l))
        return (data);
    while (ft_lstsize(data.stack_a) != 1)
    {
        if((data.stack_a)->content == (small->content))
        {
            data = push_b(data);
            small = smallest(data.stack_a);
            // distance = 0;
            // current = data.stack_a;
            // half_size = ft_lstsize(current) / 2;
            // while(current != small)
            // {
            //     distance++;
            //     current = current->next;
            // }
        }
        // if (distance == 1)
        // {
        //     data = swap_a(data);
        //     distance = 0;
        // }  
        // else if (distance >= half_size)
        // {
        //     data = reverse_rotate_a(data);
        //     distance = 0;
        // }
        // else if (distance <= half_size)
        // {
        //     data = rotate_a(data);
        //     distance = 0;
        // }
        data = reverse_rotate_a(data);
    }
    l2 = ft_lstsize(data.stack_b);
    while(l2)
    {
        data = push_a(data);
        l2--;
    }
    // if (check_if_sorted(data.stack_a) == 0)
    //     data = algorithm(data);
    return (data);
}

// t_data  algorithm_r(t_data data)
// {
//     t_list  *small;
//     int     l;
//     int     l2;

//     l = ft_lstsize(data.stack_a);
//     small = smallest(data.stack_a);
//     if ((check_if_sorted(data.stack_a) == 1) && (ft_lstsize(data.stack_a) == l))
//         return (data);
//     while (ft_lstsize(data.stack_a) != 1)
//     {
//         if((data.stack_a)->content == (small->content))
//         {
//             data = push_b(data);
//             // small = smallest(data.stack_a);
//             if (ft_lstsize(data.stack_a) == 1)
//             {
//                 l2 = ft_lstsize(data.stack_b);
//                 while(l2)
//                 {
//                     data = push_a(data);
//                     l2--;
//                 }
//                 return (data);
//             }
//             data = chose_the_next_step(data);
//         }
//         data = rotate_a(data);
//     }
//     return (data);
// }

// t_data  chose_the_next_step(t_data data)
// {
//     int     distance;
//     t_list  *small;
//     int     half_size;
//     t_list  *current = data.stack_a;

//     distance = 0;
//     current = data.stack_a;
//     half_size = ft_lstsize(data.stack_a) / 2;
//     small = smallest(data.stack_a);
//     while(current)
//     {
//         if (current == small)
//             break ;
//         distance++;
//         current = current->next;
//     }
//     if (distance >= half_size)
//     {
//         data = algorithm_r_r(data);
//     }
//     else if (distance <= half_size)
//     {
//         data = algorithm_r(data);
//     }
//     if (check_if_sorted(data.stack_a) != 1)
//         data = chose_the_next_step(data);
//     return (data);
// }