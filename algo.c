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

t_list  *mid_value(t_list *stack)
{
    t_list  *mid;
    t_list  *small;
    t_list  *big;

    small = smallest(stack);
    big = biggest(stack);

    mid = ft_lstnew(((big->content) - (small->content)) / 2);

    return (mid);
}

t_data  algorithm(t_data data)
{
    int     l;
    t_list  *small;
    t_list  *current;
    double     distance;
    double     half_size;
    int     l2;

    current = NULL;
    l = ft_lstsize(data.stack_a);
    current = data.stack_a;
    small = smallest(data.stack_a);
    distance = 0;
    half_size = (l / 2);
    while(current->content != small->content)
    {
        distance++;
        current = current->next;
    }
    // ft_printf("\n\ndistance : %d | half_size : %d\n\n", distance, half_size);
    if ((check_if_sorted(data.stack_a) == 1) && (ft_lstsize(data.stack_a) == l))
        return (data);
    while (ft_lstsize(data.stack_a) != 1)
    {
        if (distance == 1)
        {
            data = swap_a(data);
        }  
        else if ((distance > half_size) && distance)
        {
            data = reverse_rotate_a(data);
        }
        else if (((distance < half_size) || (distance == half_size)) && distance)
        {
            data = rotate_a(data);
        }
        if((data.stack_a)->content == (small->content))
        {
            data = push_b(data);
            small = smallest(data.stack_a);
            distance = 0;
            current = data.stack_a;
            half_size = (ft_lstsize(current) / 2);
            while(current->content != small->content)
            {
                distance++;
                current = current->next;
            }
        }
        // if ((check_if_sorted(data.stack_a) == 1) && (ft_lstsize(data.stack_a) == l))
        //     break ;
        // ft_printf("\n\ndistance : %d | half_size : %d\n\n", distance, half_size);
        // data = reverse_rotate_a(data);
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


// t_data  sort_stack_a_algorithm(t_data data)
// {
//     int     l;
//     t_list  *small;
//     t_list  *current;
//     double     distance;
//     double     half_size;
//     int     l2;

//     current = NULL;
//     l = ft_lstsize(data.stack_a);
//     current = data.stack_a;
//     small = smallest(data.stack_a);
//     distance = 0;
//     half_size = (l / 2);
//     while(current->content != small->content)
//     {
//         distance++;
//         current = current->next;
//     }
//     // ft_printf("\n\ndistance : %d | half_size : %d\n\n", distance, half_size);
//     if ((check_if_sorted(data.stack_a) == 1) && (ft_lstsize(data.stack_a) == l))
//         return (data);
//     while (ft_lstsize(data.stack_a) != 1)
//     {
//         if (distance == 1)
//         {
//             data = swap_a(data);
//         }  
//         else if ((distance > half_size) && distance)
//         {
//             data = reverse_rotate_a(data);
//         }
//         else if (((distance < half_size) || (distance == half_size)) && distance)
//         {
//             data = rotate_a(data);
//         }
//         if((data.stack_a)->content == (small->content))
//         {
//             data = push_b(data);
//             small = smallest(data.stack_a);
//             distance = 0;
//             current = data.stack_a;
//             half_size = (ft_lstsize(current) / 2);
//             while(current->content != small->content)
//             {
//                 distance++;
//                 current = current->next;
//             }
//         }
//     }

//     return (data);
// }

// t_data  sort_stack_b_algorithm(t_data data)
// {

//     return (data);
// }

// t_data  algorithm(t_data data)
// {
//     data = split_algorithm(data);

//     return (data);
// }

// t_data  split_algorithm(t_data data)
// {
//     int     l;
//     t_list  *mid;
//     t_list  *current;
//     // double     distance;
//     // double     half_size;
//     // int     l2;

//     current = NULL;
//     l = ft_lstsize(data.stack_a);
//     current = data.stack_a;
//     mid = mid_value(data.stack_a);
//     // distance = 0;
//     // half_size = (l / 2);
//     // while(current->content != mid->content)
//     // {
//     //     distance++;
//     //     current = current->next;
//     // }
//     // ft_printf("\n\ndistance : %d | half_size : %d\n\n", distance, half_size);
//     if ((check_if_sorted(data.stack_a) == 1) && (ft_lstsize(data.stack_a) == l))
//         return (data);
//     while (ft_lstsize(data.stack_a) && smallest(data.stack_a)->content < (mid->content))
//     {
//         // if (distance == 1)
//         // {
//         //     data = swap_a(data);
//         // }  
//         // else if ((distance > half_size) && distance)
//         // {
//         //     data = reverse_rotate_a(data);
//         // }
//         // else if (((distance < half_size) || (distance == half_size)) && distance)
//         // {
//         //     data = rotate_a(data);
//         // }
//         if((data.stack_a)->content < (mid->content))
//         {
//             data = push_b(data);
//             // mid = mid_value(data.stack_a);
//             // distance = 0;
//             // current = data.stack_a;
//             // half_size = (ft_lstsize(current) / 2); 
//             // while(current->content > mid->content)
//             // {
//             //     distance++;
//             //     current = current->next;
//             // }
//         }
//         // if ((check_if_sorted(data.stack_a) == 1) && (ft_lstsize(data.stack_a) == l))
//         //     break ;
//         // ft_printf("\n\ndistance : %d | half_size : %d\n\n", distance, half_size);
//         data = reverse_rotate_a(data);
//     }
//     // l2 = ft_lstsize(data.stack_b);
//     // while(l2)
//     // {
//     //     data = push_a(data);
//     //     l2--;
//     // }
//     // if (check_if_sorted(data.stack_a) == 0)
//     //     data = algorithm(data);
//     return (data);
// }