/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:21:40 by idouni            #+#    #+#             */
/*   Updated: 2022/11/21 11:21:43 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_putnbr_fd_r(int n)
{
	long	n2;

	n2 = n;
	if (n == -2147483648)
	{
		ft_putchar_fd_r('-');
		ft_putnbr_fd_r(2);
		ft_putnbr_fd_r(147483648);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd_r(n / 10);
		ft_putnbr_fd_r(n % 10);
	}
	else if (n < 0)
	{
		ft_putchar_fd_r('-');
		n = -n;
		ft_putnbr_fd_r(n);
	}
	else
		ft_putchar_fd_r(n + 48);
	return (ft_nbrlen(n2));
}
