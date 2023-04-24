/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:29 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/24 17:42:12 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	t_ins	fdf;

	fdf.win_wi = WIDTH;
	fdf.win_he = HEIGHT;
	ft_init_window(&fdf);
	mlx_hook(fdf.win_ptr, 2, 1L << 0, ft_close_hook, NULL);
	return (0);
}
