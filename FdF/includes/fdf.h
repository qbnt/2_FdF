/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:14 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/27 19:41:56 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"

/******* DEFINE *******/

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
# define SQUAR_SIZE 500

/*Couleurs*/
# define RED 0xFF0000
# define GREEN 0x00FF00

/*Touches*/
# define ESC 65307

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
}	t_map;

typedef struct s_3d
{
	t_sprite	loading;
	t_sprite	image;
	t_env		e;
	t_map		map;
}	t_3d;

/******* Fichiers *******/

/*mlx.c*/
int		ft_init_window(t_3d *obj);
void	ft_close_mlx(t_env *e, t_3d *obj);
int		ft_mlx(t_3d *obj);

/*key.c*/
int		key_hook(int keycode, t_3d *obj);
void	ft_free_map(int **map, int nb_line);
void	ft_free_color(char ***color, int nb_line, int nb_col);

/*error.c*/
int		ft_error(int error, t_3d *obj);

/*file.c*/
int		create_map(t_map *map, char *s, t_3d *obj);
int		*ft_compute_line(char *line, t_map *map, int **mappc, int j);

/*file1.c*/
t_bool	ft_verif_ext(const char *s, const char *ext);

/*draw.c*/
void	ft_put_pix(t_3d *obj, int x, int y, int color);
void	ft_draw(void);

/*utile.c*/
int		ft_form(char *s);
void	ft_print_tab(int **tab, int nb_line, int nb_colon);
void	ft_print_color(int **tab, int nb_line, int nb_colon);
int		ft_color(char *node);

#endif
