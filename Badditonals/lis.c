#include "push_swap.h"

static int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

void	ft_lstcpy(t_list *src, t_longest *dst, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i].val = src->content;
		src = src->next;
		i++;
	}
}

int	ft_getmax_lis(t_longest *ls)
{
	int	res;
	res = ls->i;
	ls = ls->next;
	while(ls)
	{
		res = ft_max(res, ls->i);
		ls = ls->next;
	}
	return (res);
}
t_list	*ft_get_lis(t_list *raw, int size)
{
	int	i;
	int	j;
	t_list	*lst;
	t_longest	*tmp;
	t_longest *n = ft_calloc(size,sizeof(t_longest));

	ft_lstcpy(raw, n, size);
	i = size;
	while (i--)
	{
		j = i;
		while(j < size)
		{
			if (n[j].val > n[i].val && n[j].i >= n[i].i)
			{
				n[i].next = &n[j];
				n[i].i = n[j].i + 1;
			}
			j++;
		}
	}
	i = 0;
	tmp = n;
	while (i < size)
	{
		if (n[i].i > tmp->i)
			tmp = n + i;
		i++;
	}
	lst = ft_lstnew(tmp->val, 0);
	tmp = tmp->next;
	while (tmp)
	{
		ft_lstadd_back(&lst, ft_lstnew(tmp->val,0));
		tmp = tmp->next;
	}
	free(n);
	return (lst);
}