/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:29 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/13 12:41:23 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_3d	*obj;
	char	*s;

	if (argc != 2)
		ft_error(ERROR_ARG);
	s = argv[1];
	obj = ft_calloc(1, sizeof(t_3d));
	create_map(&obj->map, s);
	ft_mlx(obj);
	return (0);
}
