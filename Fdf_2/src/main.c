/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:40:20 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/15 20:20:24 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

/******************************************************************************/

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	char	*file;

	file = argv[1];
	fdf = init_fdf(file);
	if (open(file, O_RDONLY) == -1)
		return (free(fdf), EXIT_FAILURE);
	if (argc != 2)
		return (free(fdf), EXIT_FAILURE);
	render(fdf);
	mlx_key_hook(fdf->win_ptr, &key_hook, fdf);
	mlx_expose_hook(fdf->win_ptr, &ft_expose_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
}

int	ft_expose_hook(t_fdf *fdf)
{
	render(fdf);
	return (0);
}
