/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:32 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/24 11:28:57 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_window(t_ins *soft)
{
	soft->mlx_ptr = mlx_init();
	soft->win_ptr = mlx_new_window(soft->mlx_ptr, soft->win_wi,
		soft->win_he, soft->name);
	mlx_loop(soft->mlx_ptr);
}