/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:41:06 by idouni            #+#    #+#             */
/*   Updated: 2023/02/06 20:41:22 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	char	*s;

	s = NULL;
	data.stack_a = NULL;
	data = ft_parse(data, argc, argv);
	data = check_double(data);
	if (check_if_sorted(data.stack_a) && !ft_lstsize(data.stack_b))
		ft_exit(data);
	s = get_next_line(0);
	while (s)
	{
		data = get_instruction(data, s);
		if (s)
			free(s);
	}
	if (check_if_sorted(data.stack_a) && !ft_lstsize(data.stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_exit(data);
}

t_data	get_instruction(t_data data, char *s)
{
	if (ft_strcmp(s, "ra"))
		data = ch_rotate_a(data);
	else if (ft_strcmp(s, "rra"))
		data = ch_reverse_rotate_a(data);
	else if (ft_strcmp(s, "rb"))
		data = ch_rotate_b(data);
	else if (ft_strcmp(s, "rrb"))
		data = ch_reverse_rotate_b(data);
	else if (ft_strcmp(s, "sa"))
		data = ch_swap_a(data);
	else if (ft_strcmp(s, "sb"))
		data = ch_swap_b(data);
	else if (ft_strcmp(s, "ss"))
		data = ch_swap_s(data);
	else if (ft_strcmp(s, "pa"))
		data = ch_push_a(data);
	else if (ft_strcmp(s, "pb"))
		data = ch_push_b(data);
	else if (ft_strcmp(s, "rr"))
		data = ch_rotate_r(data);
	else if (ft_strcmp(s, "rrr"))
		data = ch_reverse_rotate_r(data);
	return (data);
}
