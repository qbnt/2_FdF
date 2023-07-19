/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:14 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/19 12:13:55 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"

/******* DEFINE *******/

/*Pixel put*/
# define PIX (obj->image.pixels)
# define RED (obj->color.red)
# define GRE (obj->color.green)
# define BLU (obj->color.blue)

/*Code erreur*/
# define ERROR_ARG 1
# define ERROR_OPEN 2
# define ERROR_CLOSE 3
# define ERROR_MAP 4
# define ERROR_FORMAT 5
# define ERROR_MLX_CREA 6
# define ERROR_INTRA_MAP 7

/*Tailles*/
# define WIDTH 800
# define HEIGHT 600

/*Couleurs*/


/*Touches*/
# define ESC 65307
# define R 114
# define G 103
# define B 98
# define UP 65362
# define DOWN 65364
# define RIGHT 65361
# define LEFT 65363

/*Positions tableau*/
# define Z1PL (obj->map.map[obj->map.y][obj->map.x])
# define Z2PL (obj->map.map[obj->map.y][obj->map.x + 1])

# define Z1PC (obj->map.map[obj->map.y][obj->map.x])
# define Z2PC (obj->map.map[obj->map.y + 1][obj->map.x])

# define Z1IL (obj->map.map[obj->map.y][obj->map.x])
# define Z2IL (obj->map.map[obj->map.y][obj->map.x + 1])

# define Z1IC (obj->map.map[obj->map.y][obj->map.x])
# define Z2IC (obj->map.map[obj->map.y + 1][obj->map.x])

/******* STRUCT *******/

typedef struct s_env
{
	void	*mlx;
	void	*win;
	int		*data;
	int		bpp;
	int		width;
	int		height;
}	t_env;

typedef struct s_sprite
{
	void		*ptr;
	char		*pixels;
	int			bpp;
	int			size;
	int			endian;
	int			x;
	int			y;
}	t_sprite;

typedef struct s_map
{
	int			**map;
	int			**color_map;
	t_bool		color;
	int			x;
	int			y;
	int			nb_colon;
	int			nb_line;
	int			max;
	int			pad;
	int			proj;
}	t_map;

typedef struct s_point
{
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			spc;
	int			cte;
	int			cte1;
	int			cte2;
	int			pos;
	int			sx;
	int			sy;
	int			dx;
	int			dy;
	int			err;
	int			e2;
}	t_point;

typedef struct s_colot
{
	int			red;
	int			green;
	int			blue;
}	t_color;

typedef struct s_mov
{
	int			d_u;
	int			l_r;
}	t_mov;

typedef struct s_3d
{
	t_sprite	image;
	t_env		e;
	t_map		map;
	t_point		point;
	t_color		color;
	t_mov		mov;
}	t_3d;

/******* Fichiers *******/

/*init.c*/
void	ft_init(t_3d *obj);

/*mlx.c*/
int		ft_init_window(t_3d *obj);
void	ft_close_mlx(t_env *e, t_3d *obj);
int		ft_mlx(t_3d *obj);

/*key.c*/
int		key_hook(int keycode, t_3d *obj);
int		ft_expose_hook(t_3d *obj);

/*ft_key_color.c*/
void	ft_key_color(t_3d *obj, int keycode);

/*ft_key_move.c*/
void	ft_key_move(t_3d *obj, int keycode);

/*error.c*/
int		ft_error(int error, t_3d *obj);

/*file.c*/
int		create_map(t_map *map, char *s, t_3d *obj);
int		*ft_compute_line(char *line, t_map *map, int **mappc, int j);

/*file1.c*/
t_bool	ft_verif_ext(const char *s, const char *ext);

/*draw.c*/
void	ft_draw(t_3d *obj);

/*point.c*/
void	ft_place_colon_point_one(t_3d *obj);
void	ft_place_colon_point_two(t_3d *obj);
void	ft_place_line_point_one(t_3d *obj);
void	ft_place_line_point_two(t_3d *obj);

/*ft_bresenham.c*/
void	ft_bresenham(t_3d *obj);

/*ft_pixel_put.c*/
void	ft_pixel_put(t_3d *obj, int x, int y);

/*utile.c*/
int		ft_form(char *s);
void	ft_print_tab(int **tab, int nb_line, int nb_colon);
void	ft_print_color(int **tab, int nb_line, int nb_colon);
int		ft_color(char *node);
void	ft_free_map(int **map, int nb_line);

#endif
