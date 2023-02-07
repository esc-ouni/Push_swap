/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
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
	ft_exit (data);
}
