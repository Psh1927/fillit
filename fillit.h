/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: popanase <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:09:54 by popanase          #+#    #+#             */
/*   Updated: 2018/01/05 18:38:09 by popanase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct			s_ttrlist
{
	char				*arr;
	struct s_ttrlist	*next;
}						t_ttrlist;

typedef struct			s_sqlist
{
	char				*col;
	int					pos;
	int					mpos;
	int					fill;
	struct s_sqlist		*next;
}						t_sqlist;

typedef struct			s_res
{
	char				*s;
	int					n;
	int					qnt;
	int					flag;
}						t_res;

char					**ft_start_file_read(int fd);
int						ft_validation_block(char *res);
int						ft_validation_figure(char *res);

t_ttrlist				*ft_create_ttr_list(char **res);
void					ft_get_top_left_res(char *s);
char					*ft_get_corr_res(char *res);
int						ft_inc_ttr_len(t_ttrlist *bg_ttr, int n);
int						ft_ttrlstlen(t_ttrlist *bg_ttr);

t_sqlist				*ft_create_sq_list(t_res *r);
void					ft_add_data_sqlist(t_ttrlist *ttr, t_sqlist *sq, int n);
int						ft_pos_check(char *arr, int n);
int						ft_add_pos(char *arr, int i, char c, t_sqlist *bg_sq);
char					*ft_create_next_pos(char *arr);

int						ft_sq_size(int n);
void					ft_print_res(t_res *r);
void					ft_can_sq_two(char *s, t_res *res);
t_res					*ft_create_res(t_ttrlist *bg_ttr);
void					do_fillit(char **res);

int						ft_can_dec(t_ttrlist *bg_ttr);
void					ft_dec_ttr_len(t_ttrlist *bg_ttr);
int						ft_in_row(char *s);
void					ft_solver_case_three(t_ttrlist *bg_ttr, t_res *r);
char					*ft_create_next_pos_three(char *arr);

void					ft_cut_matrix_row(t_sqlist *bg_sq, char *col, int r_p);
void					ft_cut_matrix_char(t_sqlist *bg_sq, char c);
void					ft_add_res(t_sqlist *bg_sq, int i, char *res);
void					ft_clear_sol(t_sqlist *bg_sq, char c, t_res *r, int i);
void					ft_solver_matrix(t_sqlist *bg_sq, t_res *r, int j);

t_ttrlist				*ft_copy_ttr(t_ttrlist *src);
t_sqlist				*ft_copy_sq(t_sqlist *src);
void					ft_free_sqlist(t_sqlist *bg_sq);
void					ft_free_ttrlist(t_ttrlist *bg_ttr);

#endif
