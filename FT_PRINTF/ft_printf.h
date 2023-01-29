/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:23:15 by idouni            #+#    #+#             */
/*   Updated: 2022/11/22 09:08:05 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putunsigned_fd_r(unsigned int n);
int		ft_putnbr_fd_r(int n);
int		ft_printf(const char *f, ...);
int		ft_putchar_fd_r(char c);
int		ft_puthex_fd_r(size_t n, int t);
int		ft_putx_fd_r(unsigned int n, int t);
int		ft_putstr_fd_r(char *s);
size_t	ft_strlen_r(const char *s);

#endif
