/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:40:20 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/13 16:30:25 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	system_init(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_width = WINDOW_WIDTH;
	fdf->win_length = WINDOW_HEIGHT;
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_width, fdf->win_length,
			"Fil De Fer - qbanet");
	fdf->cam.projection = ISOMETRIC;
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	char	*s;

	s = argv[1];
	fdf = ft_calloc(1, sizeof(t_fdf));
	if (open(s, O_RDONLY) == -1)
		return (free(fdf), EXIT_FAILURE);
	if (argc != 2)
		return (free(fdf), EXIT_FAILURE);
	create_map(&fdf->map, s);
	system_init(fdf);
	mlx_key_hook(fdf->win_ptr, &key_hook, fdf);
	ft_expose_hook(fdf);
	mlx_loop(fdf->mlx_ptr);
}
