/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:24:10 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/11 17:15:58 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "libft.h"
# include "mlx.h"
# include "fdf_define.h"
# include "fdf_struct.h"

/*map_crea.c*/
void	create_map(t_map *map, char *s);

/*draw.c*/
void	ft_draw(t_fdf *fdf);

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
void	rotate(t_fdf *fdf);
void	rotate_x(t_fdf *fdf, double angle);
void	rotate_y(t_fdf *fdf, double angle);
void	rotate_z(t_fdf *fdf, double angle);

/*projection.c*/
void	project(t_fdf *fdf);

/*transform.c*/
void	transform(t_fdf *fdf);
void	scale(t_fdf *fdf, int scale_factor);
void	translate(t_fdf *fdf, int move_x, int move_y);

/*bresenham.c*/
void	bresenham(t_fdf *fdf);
void	clear_image(t_fdf *fdf, int image_size);

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