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
# include "G_N_L/get_next_line.h"

typedef struct s_list
{
	int				content;
	int				mv_a;
	int				mv_b;
	int				mv_rr;
	int				mv_rrr;
	int				mv_required;
	struct s_list	*next;
}				t_list;

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
}		t_data;

typedef struct s_rrr_data
{
	t_list	*node;
	t_list	*frst;
	t_list	*last;
	t_list	*prev;
}	t_rrr_data;

int		ft_atoi(t_data data, char *str);
t_data	check_double(t_data data);
t_data	add_to_stack(t_data data, char *str);
t_data	split_the_args(t_data data, char *str);
t_data	ft_parse(t_data data, int argc, char *argv[]);
int		ft_strcmp(const char *s1, const char *s2);
void	*h_malloc(t_data data, size_t s, void *p);
void	ft_exit(t_data data);
int		ft_abs(int n);
void	ft_exit_with_error(t_data data);

int		check_if_sorted(t_list *n);
t_data	algorithm(t_data data);
t_data	empty_a(t_data data);
t_list	*smallest(t_list *stack);
t_list	*biggest(t_list *stack);
int		moves_to_be_on_top(t_list *stack, t_list *node, double half_size);
int		moves_on_a(t_data data, t_list *node, double half_size);
t_data	moves_required(t_data data);
t_data	algo2(t_data data);
t_data	felina(t_data data);
t_data	put_min_on_top(t_data data);
t_data	sort_small_qt(t_data data);
t_data	rotate_both_stacks(t_data data, t_list *best_mem);
t_data	normal_instructions_stacks(t_data data, t_list *best_mem);
t_list	*bubblesort(t_list *n, t_list *n1, int l, int t);
int		count_distance(t_data data);
t_list	*moves(t_data data, t_list *n);
t_data	sort_5(t_data data);
t_data	empty_b(t_data data, int l);
int		mid_value(t_data data);
t_data	get_instruction(t_data data, char *s);
t_list	*count_rotation_on_both_stacks(t_list *n);

t_list	*ft_lstnew(t_data data, int content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstmap(t_data data, t_list *lst);

t_data	swap_a(t_data data);
t_data	swap_b(t_data data);
t_data	swap_s(t_data data);
t_data	push_a(t_data data);
t_data	push_b(t_data data);
t_data	rotate_a(t_data data);
t_data	rotate_b(t_data data);
t_data	rotate_r(t_data data);
t_data	reverse_rotate_a(t_data data);
t_data	reverse_rotate_b(t_data data);
t_data	reverse_rotate_r(t_data data);

t_data	ch_swap_a(t_data data);
t_data	ch_swap_b(t_data data);
t_data	ch_swap_s(t_data data);
t_data	ch_push_a(t_data data);
t_data	ch_push_b(t_data data);
t_data	ch_rotate_a(t_data data);
t_data	ch_rotate_b(t_data data);
t_data	ch_rotate_r(t_data data);
t_data	ch_reverse_rotate_a(t_data data);
t_data	ch_reverse_rotate_b(t_data data);
t_data	ch_reverse_rotate_r(t_data data);

#endif
