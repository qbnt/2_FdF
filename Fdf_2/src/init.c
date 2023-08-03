/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:59:53 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/03 13:01:44 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_window(t_fdf *fdf)
{
	if (fdf->map.nb_colon <= 10)
		fdf->win_length = fdf->map.nb_colon * 100;
	else if (fdf->map.nb_colon <= 20)
		fdf->win_length = fdf->map.nb_colon * 70;
	else if (fdf->map.nb_colon >= 20 && fdf->map.nb_colon <= 50)
		fdf->win_length = fdf->map.nb_colon * 40;
	else if (fdf->map.nb_colon >= 50 && fdf->map.nb_colon <= 100)
		fdf->win_length = fdf->map.nb_colon * 20;
	else if (fdf->map.nb_colon >= 100 && fdf->map.nb_colon <= 200)
		fdf->win_length = fdf->map.nb_colon * 10;
	else
		fdf->win_length = fdf->map.nb_colon * 10;
	if (fdf->map.nb_line <= 20)
		fdf->win_width = fdf->map.nb_line * 100;
	else if (fdf->map.nb_line >= 20 && fdf->map.nb_line <= 50)
		fdf->win_width = fdf->map.nb_line * 40;
	else if (fdf->map.nb_line >= 50 && fdf->map.nb_line <= 100)
		fdf->win_width = fdf->map.nb_line * 20;
	else if (fdf->map.nb_line >= 100 && fdf->map.nb_line <= 200)
		fdf->win_width = fdf->map.nb_line * 10;
	else
		fdf->win_width = fdf->map.nb_line * 10;
}
