/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:40:20 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/17 20:01:55 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

/******************************************************************************/

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	char	*file;

	file = argv[1];
	fdf = ft_calloc(1, sizeof(t_fdf));
	if (!fdf)
		error(3);
	if (argc != 2)
		return (free(fdf), EXIT_FAILURE);
	if (open(file, O_RDONLY) == -1)
		return (free(fdf), EXIT_FAILURE);
	init_fdf(fdf, file);
	render(fdf);
	mlx_key_hook(fdf->win_ptr, &key_hook, fdf);
	mlx_mouse_hook(fdf->win_ptr, &mouse_hook, fdf);
	mlx_expose_hook(fdf->win_ptr, &ft_expose_hook, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, &ft_end_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
}

int	ft_expose_hook(t_fdf *fdf)
{
	render(fdf);
	return (0);
}
