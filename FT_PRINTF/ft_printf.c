/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:20:45 by idouni            #+#    #+#             */
/*   Updated: 2022/11/21 11:20:48 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printfp2(va_list args, char p)
{
	int	count;

	count = 0;
	if (p == 'c')
		count += ft_putchar_fd_r(va_arg(args, int));
	else if (p == 's')
		count += ft_putstr_fd_r(va_arg(args, char *));
	else if (p == 'u')
		count += ft_putunsigned_fd_r(va_arg(args, unsigned int));
	else if (p == 'i' || p == 'd')
		count += ft_putnbr_fd_r(va_arg(args, int));
	else if (p == '%')
		count += ft_putchar_fd_r('%');
	else if (p == 'p')
	{
		count += ft_putstr_fd_r("0x");
		count += ft_puthex_fd_r((size_t)va_arg(args, void *), 1);
	}
	else if (p == 'x')
		count += ft_putx_fd_r(va_arg(args, unsigned int), 1);
	else if (p == 'X')
		count += ft_putx_fd_r(va_arg(args, unsigned int), 0);
	else if (p != '\0')
		count += ft_putchar_fd_r(p);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	i;
	int		count;
	size_t	l;

	l = ft_strlen_r(s);
	i = 0;
	count = 0;
	va_start(args, s);
	if (write(1, "0", 0) == -1)
		return (-1);
	while (i < l)
	{
		if (s[i] == '%')
		{
			i++;
			count += ft_printfp2(args, s[i]);
		}
		else
			count += ft_putchar_fd_r(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
