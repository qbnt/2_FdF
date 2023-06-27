/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:43:58 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/27 11:07:32 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_error_map(int error, t_3d *obj)
{
	if (error == ERROR_ARG)
		ft_printf("Invalid number of arguments.\n\nUsage : ./fdf <filename>\n");
	else
	{
		free(obj);
		if (error == ERROR_OPEN)
			ft_printf("Error during opening.\n");
		if (error == ERROR_INTRA_MAP)
			ft_printf("Wrong map data.\n");
		if (error == ERROR_CLOSE)
			ft_printf("Error during closing.\n");
		if (error == ERROR_MAP)
			ft_printf("Error during computing map.\n");
		if (error == ERROR_FORMAT)
			ft_printf("Error, wrong map format.\n");
	}
}

static void	ft_error_mlx(int error, t_3d *obj)
{
	if (error == ERROR_MLX_CREA)
	{
		ft_printf("Error during the mlx init.\n");
		ft_free_map(obj->map.map, obj->map.nb_line);
	}
}

int	ft_error(int error, t_3d *obj)
{
	ft_error_map(error, obj);
	ft_error_mlx(error, obj);
	exit(EXIT_FAILURE);
}
