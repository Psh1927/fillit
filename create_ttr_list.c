/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: popanase <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:19:56 by popanase          #+#    #+#             */
/*   Updated: 2018/01/18 16:04:32 by popanase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_ttrlist		*ft_create_ttr_list(char **res)
{
	t_ttrlist	*begin;
	t_ttrlist	*tmp;
	t_ttrlist	*ttr;
	int			i;

	begin = NULL;
	tmp = NULL;
	i = 0;
	while (res[i])
	{
		ttr = (t_ttrlist *)malloc(sizeof(t_ttrlist));
		if (!begin)
			begin = ttr;
		ttr->next = NULL;
		ttr->arr = ft_get_corr_res(res[i]);
		if (tmp)
			tmp->next = ttr;
		tmp = ttr;
		i++;
	}
	return (begin);
}

void			ft_get_top_left_res(char *s)
{
	char	*arr;
	int		len;
	int		i;

	arr = ft_strdup(s);
	len = ft_strlen(arr);
	while (arr)
	{
		if (ft_pos_check(arr, 4))
			ft_strcpy(s, arr);
		i = 0;
		if (arr[0] == '1')
			arr = NULL;
		else
		{
			while (i < len)
			{
				arr[i] = arr[i + 1];
				i++;
			}
			arr[len - 1] = '0';
		}
	}
	free(arr);
}

char			*ft_get_corr_res(char *res)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s = ft_strnew(16);
	while (res[i])
	{
		if (res[i] == '.')
		{
			s[j] = '0';
			j++;
		}
		else if (res[i] == '#')
		{
			s[j] = '1';
			j++;
		}
		i++;
	}
	ft_get_top_left_res(s);
	return (s);
}

int				ft_inc_ttr_len(t_ttrlist *bg_ttr, int n)
{
	int			i;
	int			j;
	char		*new;
	t_ttrlist	*tmp;

	tmp = bg_ttr;
	while (tmp)
	{
		i = 0;
		j = 0;
		new = ft_strnew(n * n);
		ft_memset(new, '0', n * n);
		while (tmp->arr[i])
		{
			if ((j + 1) % n == 0)
				j++;
			new[j++] = tmp->arr[i++];
		}
		free(tmp->arr);
		tmp->arr = new;
		tmp = tmp->next;
	}
	return (n + 1);
}

int				ft_ttrlstlen(t_ttrlist *bg_ttr)
{
	t_ttrlist	*tmp;
	int			len;

	len = 0;
	tmp = bg_ttr;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
