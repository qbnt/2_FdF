/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:41:22 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/17 00:19:45 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# include "libft.h"

typedef struct s_index
{
	int					x;
	int					y;
}	t_index;

typedef struct s_map
{
	t_index				i;
	int					**map;
	int					**color_map;
	t_bool				color;
	int					max_y;
	int					max_x;
	int					min;
	int					max;
	int					pad;
}	t_map;

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

typedef struct s_point
{
	t_index				i;
	float				x;
	float				y;
	float				z;
	int					color;
}	t_point;

typedef struct s_line
{
	t_color				colors;
	t_point				start;
	t_point				end;
	float				dx;
	float				dy;
	int					sx;
	int					sy;
	float				err;
	float				err2;
	t_bool				color;
}	t_line;

typedef struct s_img
{
	void				*ptr;
	char				*data;
	int					bpp;
	int					size;
	int					endian;
	t_line				line;
}	t_img;

typedef struct s_cam
{
	t_bool				color_pallet;
	int					projection;
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
	int					win_width;
	int					win_heigth;
	t_map				map;
	t_img				img;
	t_line				line;
	t_cam				cam;
}	t_fdf;

#endif
