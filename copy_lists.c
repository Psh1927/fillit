/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: popanase <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:12:11 by popanase          #+#    #+#             */
/*   Updated: 2018/01/18 16:12:30 by popanase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_ttrlist	*ft_copy_ttr(t_ttrlist *src)
{
	t_ttrlist	*begin;
	t_ttrlist	*dst;
	t_ttrlist	*tmp_d;
	t_ttrlist	*tmp_s;

	tmp_s = src;
	begin = NULL;
	tmp_d = NULL;
	while (tmp_s)
	{
		dst = (t_ttrlist *)malloc(sizeof(t_ttrlist));
		if (!begin)
			begin = dst;
		dst->arr = ft_strdup(tmp_s->arr);
		dst->next = NULL;
		if (tmp_d)
			tmp_d->next = dst;
		tmp_d = dst;
		tmp_s = tmp_s->next;
	}
	return (begin);
}

t_sqlist	*ft_copy_sq(t_sqlist *src)
{
	t_sqlist	*begin;
	t_sqlist	*dst;
	t_sqlist	*tmp_d;
	t_sqlist	*tmp_s;

	tmp_s = src;
	begin = NULL;
	tmp_d = NULL;
	while (tmp_s)
	{
		dst = (t_sqlist *)malloc(sizeof(t_sqlist));
		if (!begin)
			begin = dst;
		dst->col = ft_strdup(tmp_s->col);
		dst->pos = tmp_s->pos;
		dst->fill = tmp_s->fill;
		dst->next = NULL;
		if (tmp_d)
			tmp_d->next = dst;
		tmp_d = dst;
		tmp_s = tmp_s->next;
	}
	return (begin);
}

void		ft_free_sqlist(t_sqlist *bg_sq)
{
	t_sqlist *tmp;

	while (bg_sq)
	{
		free(bg_sq->col);
		tmp = bg_sq;
		bg_sq = bg_sq->next;
		free(tmp);
	}
}

void		ft_free_ttrlist(t_ttrlist *bg_ttr)
{
	t_ttrlist *tmp;

	while (bg_ttr)
	{
		free(bg_ttr->arr);
		tmp = bg_ttr;
		bg_ttr = bg_ttr->next;
		free(tmp);
	}
}
