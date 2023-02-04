/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:24:12 by idouni            #+#    #+#             */
/*   Updated: 2023/02/01 11:24:20 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_data  find_the_lis(t_data data, int l)
// {
//     int *index_arr;
//     // int *lis_values;

//     index_arr = NULL;
//     index_arr = (int *)h_malloc(data, (l * sizeof(int)) + 1, index_arr);
//     // while()
    




//     // lis_values = (int *)h_malloc(data, (max * sizeof(int)) + 1, lis_values);
//     // free(index_arr);
//     return (data);
// }

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

t_data  empty_b(t_data data, int l)
{
    while(l)
    {
        data = push_a(data);
        l--;
    }
    return (data);
}

t_data  sort_small_qt(t_data data)
{
    // if (check_if_sorted(data.stack_a))
    //     return (data);
    return (data);
}