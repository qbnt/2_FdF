/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:44:03 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/12 16:15:55 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	set_color(double fraction, int start_color, int end_color)
{
	int	red;
	int	green;
	int	blue;

	red = interpolate((start_color >> 16) & 0xFF, (end_color >> 16) & 0xFF,
			fraction);
	green = interpolate((start_color >> 8) & 0xFF, (end_color >> 8) & 0xFF,
			fraction);
	blue = interpolate(start_color & 0xFF, end_color & 0xFF, fraction);
	return ((red << 16) | (green << 8) | blue);
}

int	interpolate(int start, int end, double fraction)
{
	return (start + (end - start) * fraction);
}
