/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:31:10 by idouni            #+#    #+#             */
/*   Updated: 2022/11/12 16:18:42 by idouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ns_start(char const *s1, char const *set)
{
	size_t		l_f;
	size_t		i;

	i = 0;
	l_f = 0;
	while (s1[i])
	{
		if (check(s1[i], set) == 1)
			l_f++;
		else
			break ;
		i++;
	}
	return (l_f);
}

static int	ns_end(char const *s1, char const *set)
{
	size_t		l_e;
	size_t		l;

	l_e = ft_strlen(s1) - 1;
	l = l_e;
	while (l)
	{
		if (check(s1[l_e], set) == 1)
			l_e--;
		else
			break ;
		l--;
	}
	return (l_e);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ns;
	size_t		l;
	size_t		l_e;
	size_t		l_f;
	size_t		i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	l_f = ns_start(s1, set);
	l_e = ns_end(s1, set);
	if (l_f >= l_e)
		return (ft_strdup(""));
	l = l_e - l_f + 1;
	ns = (char *)malloc(sizeof (char) * (l + 1));
	if (!ns)
		return (0);
	while (l--)
	{
		ns[i] = s1[l_f + i];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
