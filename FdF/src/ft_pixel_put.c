/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 07:41:03 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/12 07:53:33 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put(t_3d *obj, int x, int y)
{
	if (x > 0 && y > 0 && x < obj->e.height && y < obj->e.width)
	{
		PIX[(x * (obj->e.bpp / 8)) + (y * obj->image.size)] = RED;
		PIX[(x * (obj->e.bpp / 8)) + (y * obj->image.size) + 1] = GRE;
		PIX[(x * (obj->e.bpp / 8)) + (y * obj->image.size) + 2] = BLU;
	}
}