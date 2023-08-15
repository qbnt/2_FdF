/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:24:10 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/15 13:56:19 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"
# include "fdf_define.h"
# include "fdf_struct.h"

/*map_crea.c*/
void	create_map(t_map *map, char *s);

/*draw.c*/
void	ft_endian(t_point *point, t_img *image);
void	clear_image(t_fdf *fdf, int image_size);
void	bresenham(t_line *line, t_img *img);

/*color.c*/
int		interpolate(int start, int end, double fraction);
int		set_curent_color(double fraction, int start_color, int end_color);

/*key.c*/
int		key_hook(int keycode, t_fdf *fdf);
int		ft_expose_hook(t_fdf *fdf);
int		ft_end_hook(t_fdf *fdf);

/*key_move.c*/
void	key_translate(int keycode, t_fdf *fdf);
void	key_scale(int keycode, t_fdf *fdf);
void	key_rotate(int keycode, t_fdf *fdf);
void	key_project(int keycode, t_fdf *fdf);

/*menu.c*/
void	print_menu(t_fdf *fdf);

/*rotate.c*/
void	rotate(t_line *line, t_cam *cam);
void	rotate_x(t_line *line, double angle);
void	rotate_y(t_line *line, double angle);
void	rotate_z(t_line *line, double angle);

/*projection.c*/
void	project(t_line *line, t_cam *cam);

/*transform.c*/
void	transform(t_line *line, t_cam *cam);
void	scale(t_line *line, int scale_factor);
void	translate(t_line *line, int move_x, int move_y);

/*render.c*/
void	render(t_fdf *fdf);
void	render_line(t_fdf *fdf);

/*utile.c*/
int		color(int cas, char *c_color);
void	ft_print_tab(int **tab, int nb_line, int nb_colon);
void	ft_free_int_tab(int **tab, int nb_line);
float	scale_to_fit(t_fdf *fdf);
void	reset(t_fdf *fdf);

/*utile_2.c*/
float	nb_min(float a, float b);
float	nb_max(float a, float b);
float	nb_absol(float a);

#endif