/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:32:38 by parallels         #+#    #+#             */
/*   Updated: 2023/06/28 20:31:09 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include<stdio.h>
# include<stdlib.h>
# include"minilibx/mlx.h"

# define WIDTH 800
# define HEIGHT 600

typedef struct s_env
{
	void	*mlx;
	void	*win;
	int		*data;
	int		width;
	int		height;
}	t_env;

typedef struct s_color
{
	int		color;
	int		red;
	int		green;
	int		blue;
}	t_color;

typedef struct s_img
{
	void	*ptr;
	char	*pixels;
	int		bpp;
	int		size;
	int		endian;
	int		x;
	int		y;
}	t_img;

typedef struct s_mlx
{
	t_env	e;
	t_img	image;
	t_color	color;
}	t_mlx;

#endif
