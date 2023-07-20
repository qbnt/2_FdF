/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:07:55 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/20 09:30:59 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_color(t_3d *obj, int keycode)
{
	if (keycode == R)
		obj->color.red -= 20;
	if (keycode == G)
		obj->color.green -= 20;
	if (keycode == B)
		obj->color.blue -= 20;
	return ;
}
