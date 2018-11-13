/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: popanase <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:22:05 by popanase          #+#    #+#             */
/*   Updated: 2018/01/10 17:02:34 by popanase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_cut_matrix_row(t_sqlist *bg_sq, char *col, int res_pos)
{
	t_sqlist	*tmp;
	int			i;

	i = 0;
	while (col[i])
	{
		if (col[i] != '.' && i != res_pos)
		{
			tmp = bg_sq;
			while (tmp)
			{
				if (!tmp->fill)
					tmp->col[i] = '.';
				tmp = tmp->next;
			}
		}
		i++;
	}
}

void		ft_cut_matrix_char(t_sqlist *bg_sq, char c)
{
	t_sqlist	*tmp;
	int			i;

	tmp = bg_sq;
	while (tmp)
	{
		i = 0;
		while (tmp->col[i])
		{
			if (tmp->col[i] == c && !tmp->fill)
				tmp->col[i] = '.';
			i++;
		}
		tmp = tmp->next;
	}
}

void		ft_add_res(t_sqlist *bg_sq, int i, char *res)
{
	t_sqlist	*tmp;
	char		ttr_char;

	tmp = bg_sq;
	while (tmp)
	{
		if (tmp->col[i] != '.' && !tmp->fill)
		{
			res[tmp->pos] = tmp->col[i];
			ttr_char = tmp->col[i];
			ft_cut_matrix_row(bg_sq, tmp->col, i);
			tmp->fill = 1;
		}
		tmp = tmp->next;
	}
	ft_cut_matrix_char(bg_sq, ttr_char);
}

void		ft_clear_sol(t_sqlist *bg_sq, char c, t_res *r, int i)
{
	t_sqlist	*tmp;

	tmp = bg_sq;
	while (tmp)
	{
		tmp->col[i] = '.';
		tmp = tmp->next;
	}
	i = 0;
	while (r->s[i])
	{
		if (r->s[i] == c)
			r->s[i] = '.';
		i++;
	}
}

void		ft_solver_matrix(t_sqlist *bg_sq, t_res *r, int j)
{
	t_sqlist	*tmp;
	t_sqlist	*sol;
	int			i;

	if (j == r->qnt)
		ft_print_res(r);
	sol = bg_sq;
	while (sol && !r->flag)
	{
		i = 0;
		while (sol->col[i] && !r->flag)
		{
			if (!sol->fill && sol->col[i] == 65 + j)
			{
				tmp = ft_copy_sq(bg_sq);
				ft_add_res(tmp, i, r->s);
				ft_solver_matrix(tmp, r, j + 1);
				ft_free_sqlist(tmp);
				ft_clear_sol(bg_sq, sol->col[i], r, i);
			}
			i++;
		}
		sol = sol->next;
	}
}
