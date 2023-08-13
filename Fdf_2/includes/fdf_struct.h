/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:41:22 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/13 16:39:54 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# include "libft.h"

typedef struct s_index
{
	int					x;
	int					y;
	int					z;
}	t_index;

typedef struct s_map
{
	t_index				i;
	int					**map;
	int					**color_map;
	t_bool				color;
	int					nb_line;
	int					nb_colon;
	int					min;
	int					max;
	int					pad;
}	t_map;

typedef struct s_img
{
	void				*ptr;
	char				*data;
	int					bpp;
	int					size;
	int					endian;
	int					i;
}	t_img;

typedef struct s_point
{
	t_index				i;
	t_color				colors;
	float				x1;
	float				y1;
	float				x2;
	float				y2;
	float				z1;
	float				z2;
	int					err;
	int					err2;
	int					dx;
	int					dy;
	int					sx;
	int					sy;
}	t_point;

typedef struct s_color
{
	int					start_color;
	int					start_r;
	int					start_g;
	int					start_b;
	int					end_color;
	int					end_r;
	int					end_g;
	int					end_b;
	int					delta_r;
	int					delta_g;
	int					delta_b;
}	t_color;

typedef struct s_cam
{
	int					projection;
	t_bool				color_pallet;
	float				scale_factor;
	float				transform_z;
	float				scale_z;
	float				move_x;
	float				move_y;
	double				alpha;
	double				beta;
	double				gamma;
}	t_cam;

typedef struct s_fdf
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_map				map;
	t_img				img;
	t_point				point;
	t_cam				cam;
	int					win_width;
	int					win_length;
}	t_fdf;

#endif
