/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: popanase <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:04:28 by popanase          #+#    #+#             */
/*   Updated: 2018/01/10 17:02:36 by popanase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sq_size(int n)
{
	int	qnt_ch;
	int	i;

	i = 0;
	qnt_ch = 4 * n;
	while (i * i < qnt_ch)
		i++;
	return (i);
}

void	ft_print_res(t_res *r)
{
	int	i;

	i = 0;
	while (r->s[i])
	{
		ft_putchar(r->s[i]);
		if ((i + 1) % r->n == 0)
			ft_putchar('\n');
		i++;
	}
	r->flag = 1;
}

void	ft_can_sq_two(char *s, t_res *r)
{
	if (s[0] == '1' && s[1] == '1' && s[4] == '1' && s[5] == '1')
	{
		r->s = ft_strnew(4);
		ft_memset(r->s, 'A', 4);
		ft_print_res(r);
	}
}

t_res	*ft_create_res(t_ttrlist *bg_ttr)
{
	t_res	*res;

	res = (t_res *)malloc(sizeof(t_res));
	res->qnt = ft_ttrlstlen(bg_ttr);
	res->n = ft_sq_size(res->qnt);
	res->flag = 0;
	if (res->qnt == 1)
	{
		ft_can_sq_two(bg_ttr->arr, res);
		res->n++;
	}
	if (res->n == 3)
	{
		if (ft_can_dec(bg_ttr))
			ft_solver_case_three(bg_ttr, res);
		res->n++;
	}
	return (res);
}

void	do_fillit(char **ttr)
{
	t_ttrlist	*bg_ttr;
	t_sqlist	*bg_sq;
	t_res		*r;
	int			k;

	bg_ttr = ft_create_ttr_list(ttr);
	r = ft_create_res(bg_ttr);
	k = 5;
	while (k < r->n && !r->flag)
		k = ft_inc_ttr_len(bg_ttr, k);
	while (!r->flag)
	{
		r->s = ft_strnew(r->n * r->n);
		ft_memset(r->s, '.', r->n * r->n);
		if (r->n > 4)
			ft_inc_ttr_len(bg_ttr, r->n);
		bg_sq = ft_create_sq_list(r);
		ft_add_data_sqlist(bg_ttr, bg_sq, r->n);
		ft_solver_matrix(bg_sq, r, 0);
		r->n++;
	}
	if (!r->flag)
		ft_free_sqlist(bg_sq);
	ft_free_ttrlist(bg_ttr);
	free(r);
}
