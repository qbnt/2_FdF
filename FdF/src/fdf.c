/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:29 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/24 11:28:56 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_ins	fdf;

	fdf.win_wi = 800;
	fdf.win_he = 600;
	fdf.name = "FdF";

	ft_init_window(&fdf);
	return (0);
}