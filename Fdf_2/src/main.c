/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:40:20 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/09 17:36:15 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	system_init(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	ft_window(fdf);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_width, fdf->win_length,
			"Fil De Fer - qbanet");
	fdf->point.spc = 50;
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	char	*s;

	s = argv[1];
	fdf = ft_calloc(1, sizeof(t_fdf));
	if (argc != 2)
		exit(EXIT_FAILURE);
	create_map(&fdf->map, s);
	system_init(fdf);
	mlx_key_hook(fdf->win_ptr, &key_hook, fdf);
	ft_expose_hook(fdf);
	mlx_loop(fdf->mlx_ptr);
}
