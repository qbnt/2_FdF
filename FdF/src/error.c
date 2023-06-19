/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:43:58 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/19 12:51:10 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_error(int error, t_3d *obj)
{
	if (error == ERROR_ARG)
		ft_printf("Invalid number of arguments.\n\nUsage : ./fdf <filename>\n");
	if (error == ERROR_OPEN)
		ft_printf("Error during opening.\n");
	if (error == ERROR_CLOSE)
		ft_printf("Error during closing.\n");
	if (error == ERROR_MAP)
		ft_printf("Error during computing map.\n");
	if (error == ERROR_FORMAT)
		ft_printf("Error, wrong map format.\n");
	if (error == ERROR_MLX_CREA)
	{
		ft_printf("Error during the mlx init.\n");
		ft_free_tab(obj->map.map, obj->map.nb_line);
	}
	exit(EXIT_FAILURE);
}

void	ft_free_tab(int **map, int nb_line)
{
	int	i;

	i = 0;
	while(i < nb_line)
	{
		free(map[i]);
		i ++;
	}
	free(map);
}
