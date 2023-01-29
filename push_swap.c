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
    // t_data  ata;
    // t_list  *n;

    data.stack_a = NULL;
    data = ft_parse(data, argc, argv);
    data = check_double(data);
    data = algorithm(data);

    // ata = data;
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
    // ft_printf("\n%d\n\n", check_if_sorted(n));
    // system("leaks push_swap");
    // pause();
}