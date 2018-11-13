/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_lower_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: popanase <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:48:44 by popanase          #+#    #+#             */
/*   Updated: 2018/01/17 17:48:50 by popanase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			ft_can_dec(t_ttrlist *bg_ttr)
{
	t_ttrlist	*tmp;
	int			i;

	tmp = bg_ttr;
	while (tmp)
	{
		i = 0;
		while (tmp->arr[i])
		{
			if ((i == 3 || i == 7 || i > 10) && tmp->arr[i] == '1')
				return (0);
			i++;
		}
		tmp = tmp->next;
	}
	return (1);
}

void		ft_dec_ttr_len(t_ttrlist *bg_ttr)
{
	t_ttrlist	*tmp;
	char		*new;
	int			i;
	int			j;

	tmp = bg_ttr;
	while (tmp)
	{
		i = 0;
		j = 0;
		new = ft_strnew(9);
		ft_memset(new, '0', 9);
		while (tmp->arr[i] && i < 11)
		{
			if (i == 3 || i == 7)
				i++;
			new[j++] = tmp->arr[i++];
		}
		free(tmp->arr);
		tmp->arr = new;
		tmp = tmp->next;
	}
}

int			ft_in_row(char *s)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '1' && s[i + 1] == '1')
			count++;
		i++;
	}
	return (count);
}

char		*ft_create_next_pos_three(char *arr)
{
	int		i;
	int		len;
	int		count;

	count = 0;
	len = ft_strlen(arr);
	i = len - 1;
	if (arr[i] == '1')
		return (NULL);
	if (ft_in_row(arr) != 3)
		return (ft_create_next_pos(arr));
	if (arr[i] == '1' || arr[i - 1] == '1' || arr[i - 2] == '1')
		return (NULL);
	while (i > 2)
	{
		arr[i] = arr[i - 3];
		i--;
	}
	arr[0] = '0';
	arr[1] = '0';
	arr[2] = '0';
	return (arr);
}

void		ft_solver_case_three(t_ttrlist *bg_ttr, t_res *r)
{
	t_sqlist	*bg_sq;
	t_ttrlist	*tmp;

	r->n = 3;
	tmp = ft_copy_ttr(bg_ttr);
	r->s = ft_strnew(9);
	ft_memset(r->s, '.', 9);
	ft_dec_ttr_len(tmp);
	bg_sq = ft_create_sq_list(r);
	ft_add_data_sqlist(tmp, bg_sq, 3);
	ft_solver_matrix(bg_sq, r, 0);
}
