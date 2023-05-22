/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:29 by qbanet            #+#    #+#             */
/*   Updated: 2023/05/22 15:16:32 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_3d	obj;
	char	*s;

	if (argc != 2)
		ft_error(ERROR_ARG);
	s = argv[1];
	read_map(&obj, s);
	ft_printf("y = %d\n", obj.map.y_max);
	ft_init_t_3d(&obj);
	ft_init_window(&obj.e);
	mlx_key_hook(obj.e.win, &key_hook, &obj.e);
	mlx_loop(obj.e.mlx);
	return (0);
}
