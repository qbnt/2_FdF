/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:05:29 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/02 13:56:07 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color(int cas, char *c_color)
{
	int	color;

	if (cas == 1)
		c_color = ft_strchr(c_color, ',') + 3;
	color = ft_atoi_base(c_color, 16);
	return (color);
}

void	ft_print_tab_2d(int **tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			ft_printf("%d|", tab[i][j]);
		ft_printf("\n");
	}
}
