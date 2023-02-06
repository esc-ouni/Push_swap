/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:04:09 by idouni            #+#    #+#             */
/*   Updated: 2023/01/24 14:04:38 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstnew(t_data data, int content)
{
	t_list	*new_node;

	new_node = NULL;
	new_node = (t_list *)h_malloc(data, sizeof(t_list), new_node);
	if (new_node)
	{
		new_node->content = content;
		new_node->next = NULL;
	}
	return (new_node);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	node = lst;
	while (lst != NULL)
	{
		node = lst;
		lst = lst->next;
	}
	return (node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*o_last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	o_last = ft_lstlast(*lst);
	o_last->next = new;
	new->next = NULL;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*node;
	t_list	*n_node;

	if (!lst)
		return ;
	node = *lst;
	while (node)
	{
		n_node = node->next;
		free(node);
		node = n_node;
	}
	*lst = NULL;
}

t_list	*ft_lstmap(t_data data, t_list *lst)
{
	t_list	*n_head;
	t_list	*n_next;
	t_list	*tracker;

	if (lst == NULL)
		return (NULL);
	n_head = ft_lstnew(data, lst->content);
	if (n_head == NULL)
		return (NULL);
	tracker = n_head;
	lst = lst->next;
	while (lst)
	{
		n_next = ft_lstnew(data, lst->content);
		if (n_next == NULL)
		{
			ft_lstclear(&n_head);
			return (NULL);
		}
		tracker->next = n_next;
		tracker = n_next;
		lst = lst->next;
	}
	return (n_head);
}
