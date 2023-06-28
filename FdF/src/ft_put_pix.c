/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:02:00 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/27 19:45:53 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	ft_put_pix(t_3d *obj, int x, int y, int color)
{
	char	*dst;

	dst = obj->image.ptr + (y * obj->image.size + x * (obj->image.bpp / 8));
	*(unsigned int *)dst = color;
}