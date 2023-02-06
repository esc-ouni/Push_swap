/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:04:09 by idouni            #+#    #+#             */
/*   Updated: 2023/01/24 14:04:38 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*check(t_data data, char *str)
{
	int	i;

	i = 0;
	if (str[0] == 45 || str[0] == 43 || str[0] == 48)
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_exit_with_error(data);
		i++;
	}
	return (str);
}

static long	check_l(t_data data, unsigned long nb, int s)
{
	if (nb > 2147483647 && s == 1)
		ft_exit_with_error(data);
	else if (nb > 2147483648 && s == -1)
		ft_exit_with_error(data);
	return (nb);
}

int	ft_atoi(t_data data, char *str)
{
	int				i;
	unsigned long	r;
	int				s;

	s = 1;
	r = 0;
	i = 0;
	str = check(data, str);
	while ((str[i] == 45 || str[i] == 43))
	{
		if (str[i] == 45)
			s *= -1;
		i++;
		if ((str[i] < 48 || str[i] > 57))
			ft_exit_with_error(data);
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		r = r * 10 + (str[i] - 48);
		r = check_l(data, r, s);
		i++;
	}
	return (r * s);
}

t_data	check_double(t_data data)
{
	t_list	*n;
	t_list	*n2;

	n = data.stack_a;
	while (n)
	{
		n2 = n->next;
		while (n2)
		{
			if (n->content == n2->content)
				ft_exit_with_error(data);
			n2 = n2->next;
		}
		n = n->next;
	}
	return (data);
}

t_data	empty_b(t_data data, int l)
{
	while (l)
	{
		data = push_a(data);
		l--;
	}
	return (data);
}