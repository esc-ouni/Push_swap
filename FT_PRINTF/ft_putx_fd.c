/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:22:37 by idouni            #+#    #+#             */
/*   Updated: 2022/11/21 11:22:39 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	i;

	i = 1;
	while (n > 15)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_putx_fd_r(unsigned int n, int t)
{
	int				r;
	unsigned int	n2;

	r = 0;
	n2 = n;
	if (t == 1)
		r += 32;
	if (n >= 16)
	{
		ft_putx_fd_r(n / 16, t);
		ft_putx_fd_r(n % 16, t);
	}
	else if (n >= 10 && n < 16)
	{
		ft_putchar_fd_r(n + 55 + r);
	}
	else
		ft_putchar_fd_r(n + 48);
	return (ft_hexlen(n2));
}
