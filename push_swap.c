/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:05:18 by idouni            #+#    #+#             */
/*   Updated: 2023/01/24 14:05:41 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_data  data;
    // int     mid;

    data.stack_a = NULL;
    data = ft_parse(data, argc, argv);
    data = check_double(data);
    if (argc == 6)
    {
        data = sort_5(data);
        data = empty_b(data, ft_lstsize(data.stack_b));
    }
    else if (argc > 4)
        data = algorithm(data);
    else
        data = sort_small_qt(data);

    ft_printf("\nstack_a\n");
    while(data.stack_a)
    {
        ft_printf("%d\n", (data.stack_a)->content);
        (data.stack_a) = (data.stack_a)->next;
    }
    ft_printf("\nstack_b\n");
    while(data.stack_b)
    {
        ft_printf("%d\n", (data.stack_b)->content);
        (data.stack_b) = (data.stack_b)->next;
    }
    // system("leaks push_swap");
    ft_exit(data);
    // exit(0);
}