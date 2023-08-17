/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:24:10 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/17 11:34:17 by qbanet           ###   ########.fr       */
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

/*init.c*/
t_fdf	*init_fdf(char *file);
void	init_image(t_fdf *fdf);
void	init_cam(t_fdf *fdf);

/*error.c*/
void	error(int exit_code);

/*map_crea.c*/
void	create_map(t_map *map, char *s);

/*draw.c*/
void	ft_endian(t_line *line, t_img *image, int color);
void	image_background(t_fdf *fdf);
void	bresenham(t_line *line, t_img *img);

/*color.c*/
int		get_color(t_line *line, int i_line, int size);
void	color_init(t_line *line);
void	custom_color_init(int col1, int col2, t_fdf *fdf);

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
void	rotate(t_fdf *fdf, t_cam *cam);
void	rotate_x(t_line *line, t_fdf *fdf, double angle);
void	rotate_y(t_line *line, t_fdf *fdf, double angle);
void	rotate_z(t_line *line, t_fdf *fdf, double angle);

/*projection.c*/
void	project(t_line *line, t_cam *cam, t_fdf *fdf);

/*transform.c*/
void	transform(t_fdf *fdf, t_cam *cam);
void	scale(t_line *line, int scale_factor);
void	translate(t_fdf *fdf, int move_x, int move_y);

/*render.c*/
void	render(t_fdf *fdf);
void	render_line(t_fdf *fdf);

/*utile.c*/
int		color(int cas, char *c_color);
void	ft_print_tab(int **tab, int nb_line, int nb_colon);
void	ft_free_int_tab(int **tab, int nb_line);
void	reset(t_fdf *fdf);
char	*win_name(char *str);

/*utile_2.c*/
float	nb_min(float a, float b);
float	nb_max(float a, float b);
float	nb_absol(float a);
float	scale_to_fit(t_map *map);
void	def_color(t_fdf *fdf, t_point *point);

#endif