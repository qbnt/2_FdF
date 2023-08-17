/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:05:29 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/17 11:21:56 by qbanet           ###   ########.fr       */
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
	t_index	i;

	i.x = 0;
	while (i.x < nb_line)
	{
		i.y = 0;
		while (i.y < nb_colon)
		{
			ft_putnbr_fd(tab[i.x][i.y], 1);
			write(1, "|", 1);
			i.y ++;
		}
		ft_printf("\n");
		i.x ++;
	}
}

char	*win_name(char *str)
{
	char	*res;
	char	*file;
	char	*buf;

	if (!str)
		exit(EXIT_FAILURE);
	buf = ft_strdup("Fil de fer - ");
	file = ft_strrchr(str, '/') + 1;
	res = ft_strjoin(buf, file);
	free(buf);
	return (res);
}

void	reset(t_fdf *fdf)
{
	fdf->cam.scale_factor = scale_to_fit(&fdf->map);
	fdf->cam.scale_z = 0.5;
	fdf->cam.move_x = (WINDOW_WIDTH / 2) + MENU_WIDTH / 2;
	fdf->cam.move_y = (WINDOW_HEIGHT / 2);
	fdf->cam.alpha = 0;
	fdf->cam.beta = 0;
	fdf->cam.gamma = 0;
}
