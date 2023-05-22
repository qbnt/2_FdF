/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:14 by qbanet            #+#    #+#             */
/*   Updated: 2023/05/22 15:10:36 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "libft.h"
#include "mlx.h"

/******* DEFINE *******/

/*Code erreur*/
#define ERROR_ARG 1
#define ERROR_OPEN 2

/*Tailles*/
#define WIDTH 1920
#define HEIGHT 1080
#define SQUAR_SIZE 500

/*Couleurs*/
#define RED 0xFF0000
#define GREEN 0x00FF00

/*Touches*/
#define ESC 65307

/******* STRUCT *******/

typedef struct s_env
{
	void *mlx;
	void *win;
	void *img;
	int width;
	int height;
} t_env;

typedef struct s_point
{
	int x;
	int y;
} t_point;

typedef struct s_map
{
	char **map;
	int x_max;
	int y_max;
	int z_max;
} t_map;

typedef struct s_3d
{
	t_env e;
	t_map map;
	t_point pt;
} t_3d;

/******* Fichiers *******/

/*init.c*/
void ft_init_t_3d(t_3d *obj);
void ft_init_t_env(t_env *e);
void ft_init_t_map(t_map *map);
void ft_init_t_point(t_point *point);

/*window.c*/
void ft_init_window(t_env *e);
void ft_close_window(t_env *e);

/*key.c*/
int key_hook(int keycode, t_env *e);

/*error.c*/
int ft_error(int error);

/*file.c*/
void read_map(t_3d *obj, char *s);

#endif
