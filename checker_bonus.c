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
		s = get_next_line(0);
	}
	if (s)
		free(s);
	if (check_if_sorted(data.stack_a) && !ft_lstsize(data.stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_exit(data);
}

t_data	get_instruction(t_data data, char *s)
{
	if (!ft_strcmp(s, "ra\n"))
		data = ch_rotate_a(data);
	else if (!ft_strcmp(s, "rra\n"))
		data = ch_reverse_rotate_a(data);
	else if (!ft_strcmp(s, "rb\n"))
		data = ch_rotate_b(data);
	else if (!ft_strcmp(s, "rrb\n"))
		data = ch_reverse_rotate_b(data);
	else if (!ft_strcmp(s, "sa\n"))
		data = ch_swap_a(data);
	else if (!ft_strcmp(s, "sb\n"))
		data = ch_swap_b(data);
	else if (!ft_strcmp(s, "ss\n"))
		data = ch_swap_s(data);
	else if (!ft_strcmp(s, "pa\n"))
		data = ch_push_a(data);
	else if (!ft_strcmp(s, "pb\n"))
		data = ch_push_b(data);
	else if (!ft_strcmp(s, "rr\n"))
		data = ch_rotate_r(data);
	else if (!ft_strcmp(s, "rrr\n"))
		data = ch_reverse_rotate_r(data);
	else
		ft_exit_with_error(data);
	return (data);
}
