/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sq_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: popanase <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:20:59 by popanase          #+#    #+#             */
/*   Updated: 2018/01/05 17:22:39 by popanase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_sqlist	*ft_create_sq_list(t_res *r)
{
	t_sqlist	*begin;
	t_sqlist	*sq;
	t_sqlist	*tmp;
	int			i;

	begin = NULL;
	tmp = NULL;
	i = 0;
	while (i < r->n * r->n)
	{
		sq = (t_sqlist *)malloc(sizeof(t_sqlist));
		if (!begin)
			begin = sq;
		sq->col = ft_strnew((r->n - 1) * (r->n - 1) * r->qnt);
		sq->pos = i;
		sq->fill = 0;
		sq->next = NULL;
		if (tmp)
			tmp->next = sq;
		tmp = sq;
		i++;
	}
	return (begin);
}

void		ft_add_data_sqlist(t_ttrlist *bg_ttr, t_sqlist *bg_sq, int n)
{
	t_ttrlist	*tmp;
	char		*arr;
	int			i;
	int			count;

	i = 0;
	count = 0;
	tmp = bg_ttr;
	while (tmp)
	{
		arr = ft_strdup(tmp->arr);
		while (arr)
		{
			if (ft_pos_check(arr, n) && ft_add_pos(arr, i, 'A' + count, bg_sq))
				i++;
			if (n == 3)
				arr = ft_create_next_pos_three(arr);
			else
				arr = ft_create_next_pos(arr);
		}
		count++;
		tmp = tmp->next;
	}
	free(arr);
}

int			ft_pos_check(char *arr, int n)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(arr);
	while (arr[i])
	{
		if (n > 3 && arr[i] == '1' && (i + 1) % n == 0 && arr[i + 1] == '1')
			return (0);
		i++;
	}
	return (1);
}

int			ft_add_pos(char *arr, int i, char c, t_sqlist *bg_sq)
{
	t_sqlist	*tmp;
	int			count;

	count = 0;
	tmp = bg_sq;
	while (tmp)
	{
		if (arr[count] == '1')
			tmp->col[i] = c;
		else
			tmp->col[i] = '.';
		tmp = tmp->next;
		count++;
	}
	return (1);
}

char		*ft_create_next_pos(char *arr)
{
	int		i;
	int		len;

	len = ft_strlen(arr);
	i = len - 1;
	if (arr[i] == '1')
		return (NULL);
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = '0';
	return (arr);
}
