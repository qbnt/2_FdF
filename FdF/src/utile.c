/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:52:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/05 11:50:49 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_form(char *s)
{
	s = ft_strrchr(s, '.');
	if (!s)
		return (-1);
	if (ft_strlen(s) != 4)
		return (-1);
	if (ft_strncmp(s, ".fdf", 4) == 0)
		return (0);
	return (-1);
}

void	ft_print_tab(int **tab, int nb_line, int nb_colon)
{
	int		i;
	int		j;

	i = 0;
	while (i < nb_line)
	{
		j = 0;
		while (j < nb_colon)
		{
			ft_printf("%d|", tab[i][j]);
			j ++;
		}
		ft_printf("\n");
		i ++;
	}
}

void	ft_print_color(int **tab, int nb_line, int nb_colon)
{
	int		i;
	int		j;

	i = 0;
	while (i < nb_line)
	{
		j = 0;
		while (j < nb_colon)
		{
			ft_printf("%d|", tab[i][j]);
			j ++;
		}
		ft_printf("\n");
		i ++;
	}
}

int	ft_color(char *node)
{
	char	*str;
	int		res;

	str = ft_strchr(node, 'x') + 1;
	res = ft_atoi_base(str, "0123456789ABCDEF");
	return (res);
}

void	ft_free_map(int **map, int nb_line)
{
	int	i;

	i = 0;
	while (i < nb_line)
	{
		free(map[i]);
		i ++;
	}
	free(map);
}
