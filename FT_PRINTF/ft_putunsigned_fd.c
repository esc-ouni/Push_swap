/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:22:16 by idouni            #+#    #+#             */
/*   Updated: 2022/11/21 11:22:19 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrunlen(unsigned int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_putunsigned_fd_r(unsigned int n)
{
	unsigned int	n2;

	n2 = n;
	if (n >= 10)
	{
		ft_putunsigned_fd_r(n / 10);
		ft_putunsigned_fd_r(n % 10);
	}
	else
	{
		ft_putchar_fd_r(n + 48);
	}
	return (ft_nbrunlen(n2));
}
