/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:41:22 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/08 20:35:30 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# include "libft.h"

typedef struct s_color
{
	int			red;
	int			green;
	int			blue;
}	t_color;

typedef struct s_map
{
	unsigned long long	**map;
	unsigned long long	**color_map;
	t_bool				color;
	int					def_color;
	int					nb_line;
	int					nb_colon;
	int					pad;
	int					max;
	int					min;
	int					x;
	int					y;
}	t_map;

typedef struct s_img
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			size;
	int			endian;
}	t_img;

typedef struct s_point
{
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			err;
	int			err2;
}	t_point;

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_length;
	int			proj;
	t_map		map;
	t_img		img;
	t_point		point;
	t_color		color;
}	t_fdf;

#endif
