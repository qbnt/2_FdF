/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:14 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/19 15:02:47 by qbanet           ###   ########.fr       */
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

/*Tailles*/
# define WIDTH 1920
# define HEIGHT 1080
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
	void	*img;
	int		width;
	int		height;
}	t_env;

typedef struct s_map
{
	int		**map;
	int		x;
	int		y;
	int		nb_colon;
	int		nb_line;
	int		max;
	int		pad;
}	t_map;

typedef struct s_3d
{
	t_env	e;
	t_map	map;
}	t_3d;

/******* Fichiers *******/

/*mlx.c*/
int		ft_init_window(t_3d *obj);
void	ft_close_mlx(t_env *e);
int		ft_mlx(t_3d *obj);

/*key.c*/
int		key_hook(int keycode, t_3d *obj);
void	ft_free_tab(int **map, int nb_line);

/*error.c*/
int		ft_error(int error, t_3d *obj);

/*file.c*/
int		create_map(t_map *map, char *s);

/*utile.c*/
int	ft_form(char *s);
int	*ft_inted_line(char *line, int nm_colon);
void	ft_print_tab(int **tab, int nb_line, int nb_colon);

#endif
