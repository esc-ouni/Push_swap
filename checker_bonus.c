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

	data.stack_a = NULL;
	data = ft_parse(data, argc, argv);
	data = check_double(data);
	s = get_next_line(0);
	while (s)
	{
		data = get_instruction(data, s);
		free(s);
	}
	if (check_if_sorted(data.stack_a) && !ft_lstsize(data.stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_exit(data);
}
