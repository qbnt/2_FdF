/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:40:20 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/31 13:57:09 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	system_init(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_width, fdf->win_lenght,
			"Fil De Fer - qbanet");
	fdf->img.ptr = mlx_new_image(fdf->mlx_ptr, fdf->win_width, fdf->win_lenght);
	fdf->img.data = mlx_get_data_addr(fdf->mlx_ptr, &fdf->img.bpp,
			&fdf->img.size, &fdf->img.endian);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	char	*s;

	s = argv[1];
	ft_bzero(&fdf, sizeof(t_fdf));
	if (argc != 2)
		exit(EXIT_FAILURE);
	create_map(&fdf.map, s);
	system_init(&fdf);
	mlx_loop(fdf.mlx_ptr);
}
