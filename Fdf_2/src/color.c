/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:44:03 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/17 00:42:16 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static int	color_gradient(t_line *line, float progress);

/******************************************************************************/

int	get_color(t_line *line, int i_line, int size)
{
	float	progress;

	progress = (float)i_line / (float) size;
	return (color_gradient(line, progress));
}

static int	color_gradient(t_line *line, float progress)
{
	int		r;
	int		g;
	int		b;

	r = line->colors.delta_r * progress;
	if (r < -255)
		r = 0;
	else if (r > 255)
		r = 255;
	r = r << 16;
	g = line->colors.delta_g * progress;
	if (g < -255)
		g = 0;
	else if (g > 255)
		g = 255;
	g = g << 8;
	b = line->colors.delta_b * progress;
	if (b < -255)
		b = 0;
	else if (b > 255)
		b = 255;
	return (line->colors.start_color + r + g + b);
}

void	color_init(t_line *line)
{
	line->colors.start_color = line->start.color;
	line->colors.start_r = (CO_RED & line->start.color) >> 16;
	line->colors.start_g = (CO_GREEN & line->start.color) >> 8;
	line->colors.start_b = (CO_BLUE & line->start.color);
	line->colors.end_color = line->end.color;
	line->colors.end_r = (CO_RED & line->end.color) >> 16;
	line->colors.end_g = (CO_GREEN & line->end.color) >> 8;
	line->colors.end_b = (CO_BLUE & line->end.color);
	line->colors.delta_r = (line->colors.end_r - line->colors.start_r);
	line->colors.delta_g = (line->colors.end_g - line->colors.start_g);
	line->colors.delta_b = (line->colors.end_b - line->colors.start_b);
}

void	custom_color_init(int col1, int col2, t_fdf *fdf)
{
	fdf->line.colors.start_color = col1;
	fdf->line.colors.start_r = (CO_RED & col1) >> 16;
	fdf->line.colors.start_g = (CO_GREEN & col1) >> 8;
	fdf->line.colors.start_b = (CO_BLUE & col1);
	fdf->line.colors.end_color = col2;
	fdf->line.colors.end_r = (CO_RED & col2) >> 16;
	fdf->line.colors.end_g = (CO_GREEN & col2) >> 8;
	fdf->line.colors.end_b = (CO_BLUE & col2);
	fdf->line.colors.delta_r = (fdf->line.colors.end_r
			- fdf->line.colors.start_r);
	fdf->line.colors.delta_g = (fdf->line.colors.end_g
			- fdf->line.colors.start_g);
	fdf->line.colors.delta_b = (fdf->line.colors.end_b
			- fdf->line.colors.start_b);
}
