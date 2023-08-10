/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:05:29 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/10 14:45:39 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color(int cas, char *elem)
{
	int	color;

	if (cas == 0)
		elem = ft_strchr(elem, ',') + 3;
	color = ft_atoi_base(elem, "0123456789ABCDEF");
	return (color);
}

void	ft_free_int_tab(int **tab, int nb_line)
{
	int		i;

	i = 0;
	while (i < nb_line)
	{
		free(tab[i]);
		i ++;
	}
	free(tab);
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
			ft_putnbr_fd(tab[i][j], 1);
			write(1, "|", 1);
			j ++;
		}
		ft_printf("\n");
		i ++;
	}
}
