/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:04:09 by idouni            #+#    #+#             */
/*   Updated: 2023/01/24 14:04:38 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data  ft_parse(t_data data, int argc, char *argv[])
{
    int i;

    i = 1;
    if (argc == 1)
        ft_exit(data);
    while (i < argc)
    {
        if(ft_strchr(argv[i], ' '))
            data = split_the_args(data, argv[i]);
        else
            data = add_to_stack(data, argv[i]);
        i++;
    }
    return (data);
}

t_data  split_the_args(t_data data, char *str)
{
    char    **s;
    int     i;

    i = 0;
    s = ft_split(str, ' ');
    if(s == NULL)
        ft_exit_with_error(data);
    while(s[i])
    {
        data = add_to_stack(data, s[i]);
        free(s[i]);
        i++;
    }
    free(s[i]);
    free(s);
    if(i == 0)
        ft_exit_with_error(data);
    return (data);
}

t_data  add_to_stack(t_data data, char *str)
{
    if(ft_strlen(str) == 0)
        ft_exit_with_error(data);
    ft_lstadd_back(&(data.stack_a), ft_lstnew(data, ft_atoi(data, str)));   
    return (data);
}

void  ft_exit(t_data data)
{
    if(data.stack_a)
        ft_lstclear(&(data.stack_a));
    if(data.stack_b)
        ft_lstclear(&(data.stack_b));
    exit(0);
}

void    ft_exit_with_error(t_data data)
{
    if(data.stack_a)
        ft_lstclear(&(data.stack_a));
    if(data.stack_b)
        ft_lstclear(&(data.stack_b));
    ft_putstr_fd("Error\n", 2);
    exit(1);
}

void	*h_malloc(t_data data, size_t s, void *p)
{
	p = malloc(s);
	if (!p)
	{
		ft_exit_with_error(data);
	}
	return (p);
}