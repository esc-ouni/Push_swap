/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:56:39 by idouni            #+#    #+#             */
/*   Updated: 2023/01/24 13:56:53 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "FT_PRINTF/ft_printf.h"
# include "LIBFT/libft.h"

typedef struct s_list
{
	int             content;
	struct s_list	*next;
}				t_list;

typedef struct s_data
{
    t_list      *stack_a;
    t_list      *stack_b;
}       t_data;

typedef struct s_rrr_data
{
    t_list  *node;
    t_list  *frst;
    t_list  *last;
    t_list  *prev;
}       t_rrr_data;

int     ft_atoi(t_data data, char *str);
t_data  check_double(t_data data);
t_data  add_to_stack(t_data data, char *str);
t_data  split_the_args(t_data data, char *str);
t_data  ft_parse(t_data data, int argc, char *argv[]);
void    ft_exit(t_data data);
void    ft_exit_with_error(t_data data);
int     check_if_sorted(t_list *n);
t_data  algorithm(t_data data);
// t_data  split_algorithm(t_data data);
// t_data  sort_stack_a_algorithm(t_data data);
// t_data  sort_stack_b_algorithm(t_data data);
t_list  *smallest(t_list *stack);
t_list  *biggest(t_list *stack);
// t_list  *mid_value(t_list *stack);
void	*h_malloc(t_data data, size_t s, void *p);

t_list	*ft_lstnew(t_data data, int content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));

t_data  swap_a(t_data data);
t_data  swap_b(t_data data);
t_data  swap_s(t_data data);
t_data  push_a(t_data data);
t_data  push_b(t_data data);
t_data  rotate_a(t_data data);
t_data  rotate_b(t_data data);
t_data  rotate_r(t_data data);
t_data  reverse_rotate_a(t_data data);
t_data  reverse_rotate_b(t_data data);
t_data  reverse_rotate_r(t_data data);

#endif
