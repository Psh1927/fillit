/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshchuki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:29:50 by rshchuki          #+#    #+#             */
/*   Updated: 2018/01/22 17:29:51 by rshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	char	**res;
	int		i;

	if (argc != 2)
		ft_putendl("usage ./fillit source_file");
	fd = open(argv[1], O_RDONLY);
	res = ft_start_file_read(fd);
	i = 0;
	while (res[i])
	{
		if (!ft_validation_block(res[i]) || !ft_validation_figure(res[i]))
		{
			ft_putendl("error");
			return (0);
		}
		i++;
	}
	if (i == 0 || ft_strlen(res[--i]) != 20)
	{
		ft_putendl("error");
		return (0);
	}
	do_fillit(res);
	return (0);
}

char		**ft_start_file_read(int fd)
{
	int		nbread;
	int		i;
	char	c[22];
	char	**res;

	res = (char **)malloc(sizeof(char*) * 27);
	i = 0;
	while ((nbread = read(fd, c, 21)) >= 20)
	{
		res[i++] = ft_strdup(c);
		c[20] = '\0';
		if (i > 26)
		{
			ft_putendl("error");
			exit(1);
		}
	}
	res[i] = NULL;
	if (nbread != 0)
	{
		ft_putendl("error");
		exit(1);
	}
	return (res);
}

int			ft_validation_block(char *res)
{
	int		i;
	int		g;
	int		k;

	i = 0;
	g = 0;
	k = 0;
	if (res[i] == '\0')
		return (0);
	while (*res)
	{
		if (*res == '.')
			i++;
		else if (*res == '#')
			g++;
		else if (*res == '\n')
			k++;
		res++;
	}
	if (g != 4 || i != 12 || (k != 4 && k != 5))
		return (0);
	return (1);
}

int			ft_validation_figure(char *res)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (res[i] == '#')
		{
			if ((i + 1) < (20) && res[i + 1] == '#')
				count++;
			if ((i - 1) >= (0) && res[i - 1] == '#')
				count++;
			if ((i + 5) < (20) && res[i + 5] == '#')
				count++;
			if ((i - 5) >= (0) && res[i - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}
